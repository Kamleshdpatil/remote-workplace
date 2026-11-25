/*
    g++ 01-Gstreamer.cpp -o graphicBall `pkg-config --cflags --libs gstreamer-1.0`
*/


#include<gstreamer-1.0/gst/gst.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. Initialize GStreamer
    gst_init(&argc, &argv);

    // 2. Create the pipeline using a launch string
    const char* pipeline_str = "videotestsrc pattern=ball ! videoconvert ! autovideosink";
    GError* error = nullptr;
    GstElement* pipeline = gst_parse_launch(pipeline_str, &error);

    if (!pipeline) {
        std::cerr << "Failed to create pipeline: " << (error ? error->message : "Unknown error") << std::endl;
        if (error) g_error_free(error);
        return 1;
    }

    // 3. Start playing the pipeline
    std::cout << "Starting pipeline... Press Ctrl+C to stop." << std::endl;
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    // 4. Wait until an error or End-Of-Stream (EOS) happens
    GstBus* bus = gst_element_get_bus(pipeline);
    GstMessage* msg = gst_bus_timed_pop_filtered(
        bus, 
        GST_CLOCK_TIME_NONE, 
        static_cast<GstMessageType>(GST_MESSAGE_ERROR | GST_MESSAGE_EOS)
    );

    // 5. Parse any messages if they occurred
    if (msg != nullptr) {
        if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR) {
            g_clear_error(&error);
            gst_message_parse_error(msg, &error, nullptr);
            std::cerr << "GStreamer Error: " << (error ? error->message : "Unknown") << std::endl;
            if (error) g_error_free(error);
        }
        gst_message_unref(msg);
    }

    // 6. Clean up resources
    std::cout << "Stopping pipeline and cleaning up..." << std::endl;
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
