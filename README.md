# Dictionary Benchmark

## Structure

- `src/`: Contains `Dictionary` interface and `UnsortedVectorDict` implementation.
- `.github/workflows/test.yml`: GitHub Actions CI setup.

## How It Works

1. UnsortedVectorDict.cpp is complete and the main function contains the necessary code to test it. 
2. The output provides the average run-time for the **insert** and **lookup** function. However, only the average run-time values for the unsorted vector variation is meaningful as the other variations have not been implemented yet.    
3. GitHub Actions runs 

## Run Locally

```bash
mkdir build && cd build
cmake ..
make
ctest --output-on-failure
```

## Student Information
Name: Jaime Yah-Perez
Student ID: 008856387
Repository Link: https://github.com/JaimeYahPerez/CS-315-Lab01-Repository

## Collaboration and Resources
Sorted Linked Lists:
-insert operation function is based off a previous implementation I did for a different class 
with tweaks being made to turn it from a priority queue linked list to an ascending sorted linked list
-lookup operation function is based off the implemenation done for the insert operation, but with an extra safegaurd added
to take into account special cases, within the initial while loop, and in the return line.
-Remove operation function received inspiration from the insert operation, simply now having two special cases
being dealt with initially
Sorted Vector:
-Insert operation has a basic implementation to handle search and an empty vector special case, but the use of the 
insert function call stems from seeing the usage of push_back() and an assumption that we could use it for ease of coding
-look_up and look_upidx is based off the implementation seen in unsorted vector, where the use of a binary search algorithm was used due to its' mention in lecture previously
-remove utilizes the erase function out of an assumption that we could utilize these vector function calls

All dictionary implementations had debugging assistance through the use of chatgpt, which did lead to some tweaks being done for serious bugs
such as one for the binary search algorithm in the sorted vector one for a while loop in the unsorted linked list. Such as ensuring that statements were not unnecessarily redundant, 
but also making sure special cases were covered

Insert and Erase were utilized under the assumption we could utilize them to prevent doing excessive work for our implementations

-unsorted Linked list was implemented completely based off what was done in sorted linked lists

## Implementation Details
Both linked lists dictionarys utilize a basic node traversal while loop that checks for an existing null ptr in its' path, along for the desired key value. 
In some cases, the loop checks further ahead for that key, or checks if the starting and current node exist. Thsse two being used are dependent on what special cases exist for the dictionary
operation, and whether or not a special action must be taken, such as for an early insertion or removal. And for a regular removal, a need to to stop at the node prior to the one chosen for removal.

Comparisons being made with the given key and our node value are dependent on whether or not sorting has been done, with the only difference being that we either stop prior to or at that chosen node.

removal and insertion both simply utilize splicing with a new temporary/x node being made for connecting nodes together at that specific indice. Searching is only done for the sorted linked list
up until values larger than the key are found, in which it is added after any existing duplicates. And for removal, the first duplicate is chosen for deletion with the search method.
But only after verification that the found node contains our desired key.

Sorted Vectors makes use of a helper lookup function, that utilizes the binary search algorithm to locate the desired index, and return that index value for later use.
Such as in the remove and look_up operations, where the given index is verified to see if our key exists. 

insert operation performs the sorting as insertion occurs, where after the initial special case of an empty vector is checked, an ascending search occurs looking for the first value bigger
than our key, where an insert function call will then be made afterwards to splice in our key, which also places it at the end of any potential duplicates

splicing and the lookup helper function is utilized for the remove function, which works similarly as an erase function call is used for removal and splicing at a given index location
both erase and insert automatically handle the reorganization of the vector and resizing

the adjustments in main.cpp for removal testing were based completely on already finished code for the other test, with lookups being used again for this test

## Testing and Status
With the 5000 benchmark, all tests were completed in reasonable time, and most tests for 500000 are completed in reasonable time, apart from sorted linked lists which has appeared to take
beyond 2 hours. 

