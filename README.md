Group Members: </br>
Barry Ibarra </br>
Viet Le</br>
</br>
For both calculate and verify, input can be by console or file input. Sample file input will be provided.</br>
</br>
For Calculate algorithm:</br>
Compiled with:</br>
g++ calculate.cpp -o calculate</br>
</br>
Executed with:</br>
./calculate</br>
</br>
File Input: Executed with </br>
./calculate < calc_sample_input.txt</br>
</br>
File Input: The events for each process is entered with a newline between each process.</br>
Look at calc_sample_input.txt for an example.</br>
</br>
Input is by console: Input the events for each processes. </br>
Test Case #1:</br>

a1 s1 r3 b </br>
c r2 s3 NULL </br>
r1 d s2 e </br>

Number of processes(N) can be changed by changing the #define N statement </br>
Number of events(M) can be changed by changing the #define M statement at line 11</br>
</br>
When prompted for first process: a1 s1 r3 b is entered</br>
When prompted for second process: c r2 s3 NULL is entered</br>
When prompted for third process: r1 d s2 e is entered</br>
</br>
If there is no event in a process, NULL must be entered.</br></br>
Test Case #2:</br>
s1 b r3 e</br>
a r2 s3 NULL</br>
r1 c d s2</br>
When prompted for first process: s1 b r3 e is entered</br>
When prompted for second process: a r2 s3 NULL is entered</br>
When prompted for third process: r1 c d s2 is entered</br>
</br>
</br>
</br>
For Verify algorithm: </br>
Compiled with:</br>
g++ verify.cpp -o verify</br>
</br>
Executed with:</br>
./verify</br>
</br>
File Input: Executed with: </br>
./verify < verify_sample_input.txt</br>
</br>
File Input: The LC values for each process is entered, and then the events for each process, with a new line between each process.</br>
Look at verify_sample_input.txt for an example.</br>
</br>
Input is by console: First, we must enter the LC values for each process and then the user will be prompted to enter the events of each process next. After doing so, the command prompt will then display the result.</br>

Test Case #1: </br>
1 2 7 9</br>
1 6 7 0</br>
2 3 4 5</br>
When prompted for first process: 1 2 7 9 is entered</br>
When prompted for second process: 1 6 7 0 is entered</br>
When prompted for third process: 2 3 4 5 is entered</br>
</br>
s1 b r3 e</br>
a r2 s3 NULL</br>
r1 c d s2</br>
When prompted for first process: s1 b r3 e is entered</br>
When prompted for second process: a r2 s3 NULL is entered</br>
When prompted for third process: r1 c d s2 is entered</br>
</br>
Test Case #2: </br>
1 2 8 9 </br>
1 6 7 0 </br>
2 3 4 5 </br>
When prompted for first process: 1 2 8 9 is entered</br>
When prompted for second process: 1 6 7 0 is entered</br>
When prompted for third process: 2 3 4 5 is entered</br>
</br>
s1 b r3 e</br>
a r2 s3 NULL</br>
r1 c d s2</br>
When prompted for first process: s1 b r3 e is entered</br>
When prompted for second process: a r2 s3 NULL is entered</br>
When prompted for third process: r1 c d s2 is entered</br>
