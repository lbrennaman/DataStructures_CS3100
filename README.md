# DataStructures_CS3100

This repository contains all of the c++ files I created during my data structures class at Wright State. (Ended class with an A)

/bintree contains my own implementation of a binary tree data structure. Not much work was put into it. /p2 is a much better display of this data structure since it was a 
  project.

/cppintro contains references I use to remind myself of c++ syntax.
  //arrinit reminds me how to initialize arrays with an already known list.
  //class shows the syntax to create a class when separating the class into a .cpp file and a .h file. (This is without templates)
  //delete (uses a bit of Japanese in things like the name of the files, variable names, and print statements) seems to be demonstrating deconstructor usage
  //excep shows the syntax for throwing a custom exeption
  //io shows how to handle inputing and outputting to a file
  //it displays how to use iterators (I am still unfamilar with them [1/18/2022])
  //miscStart appears to be files our professor had us create to practice c++ syntax. For example, one such file is as simple as "Hello, World!"
  //overload shows the syntax for overloading the = and << operator using a class split into a .cpp file and a .h file (with templates, not optimal syntax)
  //point: reminder of pointer syntax and usage
  //quicksort: a quicksort I attempted to do from memory but never ended up finishing
  //rand: the proper syntax for a random number generator between a lower and upper bound [lower, upper]
  //svh: stack versus heap implementation of objects
  //template: example class using templates
  
/llist is my own LinkedList implementation since I'm not familiar with iterators in c++ and therefore not much of a fan for them since they seem tedious to use.
  I believe that this implementation isn't as complete as the one I used to implement project 2. (/p2)
  
/p1 is the SparseMatrix implementation I scored a 75% on for coding it perfectly yet not understanding the directions. (See /proPlans/p1plan.txt to see the instructions for p1 
  and the starter code we were given. I was confused by the directions saying directly underneath where it says "Overview." It recommends to use a list so I had expected to 
  see a single dimensional array, but upon seeing the code I saw a 2d array, which we were told not to use. Seeing this declaration made me think that I was going to be 
  creating a matrix where each spot was filled -- very clearly not what the directions said -- but if this was the code we were given, then I was going to follow the code we 
  were given over the instructions, thinking that if we were given starter code then we probably weren't meant to change it. In the end, I received a 75% for having come to 
  this conclusion and was given no way to explain my thinking to the professor.)
  
/p2 is my favorite project from my data structures class as it was the ONLY PROJECT IN WHICH WE DIDN'T RECEIVE STARTER CODE. The goal of this project (see /proPlans/p2plan.txt 
  for exact instructions) was to simulate a file tree using a binary tree. I finished this project in about 8 hours after the project was released and the grade I received on 
  it was -- I believe -- 105%. This project was fun and I don't think I had any problems with the directions on this one...
  
 /p3 was to build a HashTable, and it certainly created some confusion. We were taught that a hashTable is a data structure much like an array, each address being a key.
  Given a certain value, a hash is applied to that value and maps the value to a key, a place in the hashTable. What was confusing about this project was that we were given a
  key (an int) and a value (of generic type T), that much is the same as we were taught -- there is a key and a value. The problem with that is that the value we were given 
  wasn't an integer, so there was no way to apply a hash function to it. Well, I could probably come up with one, but it's not something we were ever taught. All of the previous
  values we'd seen examples of had used integers as the value -- AND -- the directions also made it sound as if the value we were meant to use the hash function on AND THEN
  insert into the hashTable was the key. In that case, where did the value come into play? What were we supposed to do with the value if the hash function was used to map 
  the key to a location and then stored in that same location? To me, it sounded as if we were supposed to place both the key and the value in the same location, which is
  -- I believe -- what I did.
    There are also four of these p3s since we were told to keep track of four different combinations of hash and probe functions...
    
  /p4 was incredibly tedious. The /not folder contains a graph implementation using linked lists that our professor coded for us in class during multiple lectures.
    The /p4 is the implementation I coded. The project started off with being told to take our professor's code and change it into a matrix based graph implementation. This took
    way too long, as her code was not very close to my style of formatting. Only after converting the style of graph implementation could I begin implementing the actual 
    functions, of which -- because our professor had used data structures that used iterators -- it was hard to find a way to adapt to the code. In the end, I think my code is
    vert neat and cleanly implemented, but it was annoying to get it to such a state. 
    
  /proPlans contains the instructions given for each project. I don't think this is in each file, but the reason they're called proPlans is because I plan how to code each 
    project after I list the instructions in each file. The other two files in there are failed attempts at coding project 3.
