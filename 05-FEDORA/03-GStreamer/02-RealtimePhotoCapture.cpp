/*
    g++ 02-RealtimePhotoCapture.cpp -o RealtimePhotoCapture `pkg-config --cflags --libs gstreamer-1.0`

*/

#include<iostream>
#include<gstreamer-1.0/gst/gst.h>
#include<string>
#include<chrono>
#include<iomanip>
#include<sstream>
#include<filesystem>

using namespace std;

// input: empty string filePath as a reference
// output: Folder creation with name of current date (Every day new folder), 
// and return file name in filepath string
void createOutputPathToStoreFrames(string& filePath)
{
    auto now = std::chrono::system_clock::now();
    auto localTime = std::chrono::system_clock::to_time_t(now);

    std::stringstream fileNameBuffer;
    std::stringstream folderNameBuffer;

    fileNameBuffer << std::put_time(std::localtime(&localTime), "%Y-%m-%d_%H-%M-%S");
    folderNameBuffer << std::put_time(std::localtime(&localTime), "%Y-%m-%d");

    string folderName = folderNameBuffer.str() + "/";
    try{
        if(!filesystem::exists(folderName)){
            filesystem::create_directories(folderName);
        }
    }catch(const filesystem::filesystem_error& e){
        std::cerr<<"Failed to create directory structure: "<<e.what();
        return;
    }

    filePath = folderName + fileNameBuffer.str() + ".jpg";
}

int main(int argc, char* argv[])
{
    // 1. Initilize GStreamer
    gst_init(&argc, &argv);

    // 2. photograph path with current time stamps for name of frame.
    string frameName;
    createOutputPathToStoreFrames(frameName);

    // 3. Build the pipeline string 
    // num-buffers=1 tells the camera source to drop only 1 frame and strop

    std::string pipeline_str = "v4l2src num-buffers=1 ! videoconvert ! jpegenc ! filesink location=" + frameName;

    GError* error = nullptr;

    GstElement* pipeline = gst_parse_launch(pipeline_str.c_str(), &error);
    if(!pipeline){
        std::cerr << "Pipeline creation failed: "<<(error ? error->message : "Unknown error")<<endl;
        if(error)
            g_error_free(error);
        return 1;
    }

    // 4. Start the camera and capture the frame
    std::cout<<"Capturing photo frames from camera..."<<endl;
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    // 5. Wait for the pipeline to finish saving the file (EOS = End of Stream)
    GstBus* bus = gst_element_get_bus(pipeline);
    GstMessage* msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, static_cast<GstMessageType>(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

    // 6. Check for errors during execuation
    if(msg != nullptr){
        if(GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR){
            g_clear_error(&error);
            gst_message_parse_error(msg, &error, nullptr);
            std::cerr<< "GStreamer Error: "<< (error ? error->message : "Unknown") <<std::endl;
            if(error)
                g_error_free(error);
        }else if(GST_MESSAGE_TYPE(msg) == GST_MESSAGE_EOS){
            std::cout<<"Frame successfully saved to : "<<frameName<<std::endl;
        }
        gst_message_unref(msg);
    }

    // 7. Clean up
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return(0);
}
