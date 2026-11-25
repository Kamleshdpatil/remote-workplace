#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// Comparators
template<typename T>
T internalComparator(T a, T b){
    if(a > b) return true;
    return false;
}

bool intComparator(int a, int b){
    return a > b;
}

template<typename T, typename P>
bool pairComparator(pair<T ,P> a, pair<T ,P> b){
    if(a.second > b.second) return false;
    return true;
}

template<typename T, typename P>
bool pairComparator2(pair<T ,P> a, pair<T ,P> b){
    if(a.first > b.first) return false;
    return true;
}

/// @brief ////////////////////////////////////////////////

void explainPair()
{
    // pair<int, int> pr = {2, 8};
    pair<int, char> pr = {2, 'K'};

    // cout<<pr.first<<" "<<pr.second<<" "<<endl;

    // pair<pair<int, char>, int> pr2 = {pr, 10};
    pair<pair<int, char>, int> pr2 = {{4, 'G'}, 10};
    cout << pr2.first.first << " " << pr2.first.second << " " << endl;
}

void explainVector()
{
}

void explainList()
{
    list<int> ls = {11, 21};

    ls.push_back(10);
    ls.push_front(50);
    ls.emplace_front(55);

    for (auto i : ls)
    {
        cout << i << " ";
    }
}

void explainQueue()
{
    // Queue
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(10);
    qu.push(30);
    qu.push(10);
    qu.push(30);
    qu.push(20000);

    cout << qu.front() << endl;
    qu.pop();

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
}

void explainStack()
{
    // Stack
    stack<int> st;
    try
    {

        st.push(10);
        st.push(20);
        st.push(10);
        st.push(30);
        st.push(10);
        st.push(30);
        st.push(20000);

        cout << st.top() << endl;
        st.pop();

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void explainPQueue()
{
    // PQueue

    // Store max first
    priority_queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(10);
    qu.push(30);
    qu.push(10);
    qu.push(30);
    qu.push(20000);

    // cout<<qu.top()<<endl;
    // qu.pop();

    // while(!qu.empty()){
    //     cout<<qu.top()<<" ";
    //     qu.pop();
    // }

    // Store min first
    priority_queue<int, vector<int>, greater<int>> minQue;
    minQue.push(10);
    minQue.push(20);
    minQue.push(10);
    minQue.push(30);
    minQue.push(10);
    minQue.push(30);
    minQue.push(20000);
    cout << minQue.top() << endl;
    minQue.pop();

    cout << "Printing all elements: " << endl;

    while (!minQue.empty())
    {
        cout << minQue.top() << endl;
        minQue.pop();
    }
}

void explainSet()
{
    // Set - Stores only unique elements in ascending order only.
    set<int> st;
    st.insert(10);
    st.insert(12);
    st.insert(21);
    st.insert(60);
    st.insert(900);
    st.insert(800);
    st.insert(40);
    st.insert(5);

    cout << endl;
    cout << "Printing all Elements: " << endl;
    cout << endl;

    for (auto i : st)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << "Type element for search in Set: " << endl;
    // -- To check element is present or not
    auto input = 0.0;
    cin >> input;

    auto it = st.find(input);

    if (it != st.end())
    {
        cout << "Element found: " << *it << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }
}

void explainMultiSet()
{
    // MultiSet
    multiset<int> ms;
    ms.insert(99);
    ms.insert(19);
    ms.insert(20);
    ms.insert(20);
    ms.insert(34);
    ms.insert(34);
    ms.insert(21);

    for (auto i : ms)
    {
        cout << i << " " << endl;
    }
    cout << endl;

    // auto i = ms.find(2088);
    // cout<<*i<<endl;

    cout << ms.count(34);
}

void explainUnorderedSet()
{
    // Unordered Set
    unordered_set<int> st;

    st.insert(10);
    st.insert(12);
    st.insert(21);
    st.insert(60);
    st.insert(900);
    st.insert(800);
    st.insert(800);
    st.insert(800);
    st.insert(40);
    st.insert(5);

    cout << endl;
    cout << "Printing all Elements: " << endl;
    cout << endl;

    for (auto i : st)
    {
        cout << i << " ";
    }
}

void explainMap()
{
    map<int, string> mpp;
    mpp[1] = "Kamlesh";
    mpp[4] = "Gouri";
    mpp[3] = "Shivani";
    mpp[2] = "Nandu";

    mpp.insert({5, "Laadu"});
    mpp.insert({0, "Shreya"});

    for (auto it : mpp)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << endl;
    // cout<<endl;
    // cout<<(*(mpp.find(3))).second<<endl;
}

void explainMultiMap()
{
    multimap<int, string> mpp;
    mpp.insert({1, "Kamlesh"});
    mpp.insert({3, "Gouri"});
    mpp.insert({2, "Shivani"});
    mpp.insert({5, "Laadu"});
    mpp.insert({5, "Laadu"});
    mpp.insert({5, "Nandu"});
    mpp.insert({5, "Laadu"});

    for (auto it : mpp)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << endl;

    auto it = mpp.equal_range(5);
    for (auto i = it.first; i != it.second; i++)
    {
        cout << (*i).first << "-> " << (*i).second << endl;
    }

    cout << endl;
}

void explainSort()
{
    // Sort
    int arr[5] = {2, 15, 8, 11, 9};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + 4);

    cout << "After sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void explainOtherFunctions()
{
    // // Acummulate //
    // int arr[5] = {2, 15, 8, 0, 9};
    // for(int i = 0; i < 5; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // // #include <numeric>
    // cout<<"Acummulate: "<<std::accumulate(arr, arr + 5, 1);

    // cout<<endl;

    // // // Count // //
    // int arr[] = {2, 15, 8, 1, 8, 34, 8, 9};
    // for(int i = 0; i < 8; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // // #include <numeric>
    // cout<<"Count: "<<std::count(arr, arr + 8, 8);

    // // Find // //
    vector<int> arr = {2, 15, 8, 1, 8, 34, 8, 9};
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // #include <numeric>
    auto num = find(arr.begin(), arr.end(), 8);
    if (num != arr.end())
    {
        cout << "Find: " << *num << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

void explainNextPermutation()
{
    // // Permutations //
    // string str = "bca";
    // do{
    //     cout<<str<<endl;
    // }while (next_permutation(str.begin(), str.end()));

    // cout<<endl;

    // string str1 = "abc";
    // do{
    //     cout<<str1<<endl;
    // }while (next_permutation(str1.begin(), str1.end()));

    string str = "bca";
    do
    {
        cout << str << endl;
    } while (prev_permutation(str.begin(), str.end()));

    cout << endl;

    string str1 = "abc";
    do
    {
        cout << str1 << endl;
    } while (prev_permutation(str1.begin(), str1.end()));
}

void explainMaxElement()
{
    // Max & Min Element
    int arr[5] = {2, 15, 8, 111, 9};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Max element is: " << *max_element(arr, arr + 5) << endl;
    cout << "Min element is: " << *min_element(arr, arr + 5) << endl;
}

void explainReverse()
{
    // Reverse the array
    int arr[5] = {2, 15, 8, 111, 9};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse(arr, arr+5);

    cout << "After reverse"<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

void explainComparator()
{
    // // int arr[5] = {2, 15, 8, 111, 9};
    // vector<int> arr = {2, 15, 8, 111, 9};
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // sort(arr.begin(), arr.end(), internalComparator<int>);

    // cout << "After sorting"<< endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // int arr[5] = {2, 15, 8, 111, 9};

    // // Pair comparator // //
    pair<int, int> intPair[] = {{2, 2}, {3, 22}, {2, 12},{4, 28},{6, 10}};
    for (auto item : intPair)
    {
        cout << item.first << " ";
        cout << item.second << " ";
        cout << endl;
    }
    cout << endl;

    // sort(intPair, intPair+5, pairComparator<int, int>);

    // cout << "After sorting"<< endl;
    // for (auto item : intPair)
    // {
    //     cout << item.first << " ";
    //     cout << item.second << " ";
    //     cout << endl;
    // }
    // cout << endl;
    sort(intPair, intPair+5, pairComparator2<int, int>);

    cout << "After sorting"<< endl;
    for (auto item : intPair)
    {
        cout << item.first << " ";
        cout << item.second << " ";
        cout << endl;
    }
    cout << endl;

    
}

int main()
{
    // explainPair();
    // explainVector();
    // explainList();
    // explainStack();
    // explainQueue();
    // explainPQueue();
    // explainSet();
    // explainMultiSet();
    // explainUnorderedSet();
    // explainMap();
    // explainMultiMap();
    // explainSort();
    // explainOtherFunctions();
    // explainNextPermutation();
    // explainMaxElement();
    // explainReverse();
    explainComparator();
    return (0);
}