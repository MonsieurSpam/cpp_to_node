#include <iostream>
#include <curl/curl.h>

using namespace std;
//compile with g++ helloworld.cpp -l curl

void updateData(string updateString,CURL* curl){
    CURLcode res;
    curl_easy_setopt(curl,CURLOPT_POSTFIELDS, updateString.c_str());
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Error"<< endl;
    } 
}

int main() {
    CURL *curl;
    struct curl_slist *headers = NULL;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);

    // Create curl handle
    curl = curl_easy_init();
    if (curl) {
        // Set URL and request type
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/api/postdata");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set request headers
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }

    int counter = 0;

    while(1){
        string data = "param1="+to_string(counter);
        updateData(data,curl);
        counter++;
    }

        

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    // Clean up libcurl
    curl_global_cleanup();

    return 0;
}

