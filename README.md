# cpp_to_node
Code snippet that allows cpp program to continuously send HTTPS requests to NodeJs server. This code was written for FEB as part of a datalogger project where a C++ program
running on a Raspberry Pi would send post requests to a node server on the Pi in order to display vehicle information. Uploaded as reference for future use.

# Required libraries 
This project uses the curl library for C++ and the express package for NodeJs. Make sure you have both of these packages and libraries installed before using this project

# Install and Run
1) Clone the project.
2) Open a terminal and navigate to cpp_to_node/cpp_program. Compile the cpp program with the following command "g++ helloworld.cpp -l curl"
3) Open a new terminal in basic_express_server. Start the express server with the command "node index.js"
4) Once the server has started, return to the terminal from Step 2 and run the following "./a.out" 
