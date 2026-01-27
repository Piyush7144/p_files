1. Design a data structure that supports insert, delete, search and getRandom in constant time

https://www.geeksforgeeks.org/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time/



2. Top view of a binary tree:



3. Design irctc , a website to book train

1. schedulate a train(search)
2. book a single seat in given train(or multiple)
3. train has-> route (stop, time)
   seat arrangement
3.5 tatkal booking 
4. month advance booking
5. Parallel seal booking
6. Cancellation -> no booking
   wrong booking


4. Given are the heights of certain Buildings which lie adjacent to each other. Sunlight starts falling from the left side of the buildings. If there is a building of a certain Height, all the buildings to the right side of it having lesser heights cannot see the sun. The task is to find the total number of such buildings that receive sunlight.


Input:
N = 6
H[] = {6, 2, 8, 4, 11, 13}
Output:
4
Explanation:
Only buildings of height 6, 8, 11 and
13 can see the sun, hence output is 4.


5. Reverse a linked list in group of given size

Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
Output: 3->2->1->6->5->4->8->7->NULL 
Input: 1->2->3->4->5->6->7->8->NULL, K = 5 
Output: 5->4->3->2->1->8->7->6->NULL 


6. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.



7. In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is 
replaced with a new selected color. Following is the problem statement to do this task. 

Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and 
all adjacent same colored pixels with the given color.



Input:
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 2, 2, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 2, 2, 0},
               {1, 1, 1, 1, 1, 2, 1, 1},
               {1, 1, 1, 1, 1, 2, 2, 1},
               };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen
  indicate colors of the pixels.
x and y are coordinates of the brush,
   newColor is the color that
should replace the previous color on 
   screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 3, 3, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 3, 3, 0},
               {1, 1, 1, 1, 1, 3, 1, 1},
               {1, 1, 1, 1, 1, 3, 3, 1},
               };


8. Generate all Balanced Parentheses

Input : n=2
Output: 
{}{}
{{}}
Explanation: This the only two sequences of balanced 
parenthesis formed using 2 pair of balanced parenthesis.''



9. System design interview



Design a calendar Application (similar on lines with Google'''s Calendar)
It should support the following functionalities:

1. Ability to create, update, delete an Event
a. An event would typically consist of {start, end, location, Owner, user-list, title}.
b. Events can either be like meetings(with a dedicated location and appropriate guest-list) or as well be like holidays, birthdays, reminders etc.
c. An event once created, can be either accepted or rejected by the constituent users - if neither it should be in neutral state.
2. Get Calendar for a user Ui
3. Get Event details.
4. For a given set of users[U1, U2,....Un] identity a common free slot of time.


Class User{
private String name;
private String occupation;
private Calendar calendar;
private String email;
private String conctact;
.
.
.
}

Class Calendar{
Enums DAYS,MONTHS,YEARS;
private Event event;
.
.
.
}

Class Event{
private String type;
private LocalDateTime startTime;
private LocalDateTime endTime;
private int duration;
}

Class Meeting extends Event{
private String type = "Meeting";
private String agenda;
.
.
}

Class Reminder extends Event{
private String type = "Reminder";
private String remiderNote;
.
.
}



Requirements:

add events
reminders
timezone
invite users to events


entities

calender
users
events
notification
notificationChannel



User:

id:
name:
email:


calender:

id:
name:
description:
timezone:


events:

id:
name:
description:
start:
end:
allDay:


notification:

id:  
effective: datatime


notficationChanne:

id:
method:
value:




10. Design Parking lot 

i. First get the requirements

a. Big parking losts  10k - 30k parkings
b. 4 - entrances , 4 exits
c. Ticket and spot attached at entrances
d. Parkig spot should be nearest to the entrance 
e. limit/ capacity - 30, 0000
f. Parking spots: HC, compact, large vehecle , motorcycle
h. Hourly rate 
i. cash/credit card accepted
j. Monitoring system

Non-function requirement: 
1. code reuserability


Parking lot sytem design:

1. Parking lot system
2. Entry/exit terminds
   - printers
   - payment processes
3. Parking spot  
4. Ticket 
5. Database  
6. Monitoring system  




Parking ticket:
- id 
- parkingSpotId
- parkingSpotType
- IssueTime




Questions:

1. Compilte time polymorphism and runtime polymorphism
2.  What is a copy constructor? Shallow and deep copy
3. Explain the Singleton pattern?
Singleton pattern in Java is a pattern which allows a single instance within an application. 
One good example of the singleton pattern is java.lang.Runtime.

Singleton Pattern states that define a class that has only one instance and provides a global 
point of access to it.

In other words, it is the responsibility of the class that only a single instance should be created,
 and all other classes can use a single object.


4.  Observer Pattern
An Observer Pattern says that "just define a one-to-one dependency so that when one object changes state, 
all its dependents are notified and updated automatically".

The observer pattern is also known as Dependents or Publish-Subscribe.

5. Strategy Pattern
A Strategy Pattern says that "defines a family of functionality, encapsulate each one, and make them interchangeable".

The Strategy Pattern is also known as Policy.


6. What are the SOLID Principles?

SOLID Principles is an acronym of 5 principles in Object Oriented Design (OOD). Robert C. Martin introduced these 
5 principles in his 2000 paper "Design Principles and Design Patterns".

S - Single Responsibility Principle
O - Open Closed Principle
L - Liskov Substitution Principle
I - Interface Segregation Principle
D - Dependency Inversion Principle


7. Process-based and Thread-based multitasking in Java 


8. What is Daemon Thread in Java and explain their properties? 

Daemon thread is a low-priority thread that runs in the background to perform tasks 
such as garbage collection. It does possess certain specific properties as listed below:

They can not prevent the JVM from exiting when all the user threads finish their execution.
JVM terminates itself when all user threads finish their execution
If JVM finds a running daemon thread, it terminates the thread and after that shutdown itself. 
JVM does not care whether the Daemon thread is running or not.
It is an utmost low priority thread.  


9. What does join() method?
The join() method waits for a thread to die. In other words, it causes the currently running 
threads to stop executing until the thread it joins with completes its task. Join method is 
overloaded in Thread class in the following ways.

public void join()throws InterruptedException
public void join(long milliseconds)throws InterruptedException

10. What do you understand by thread pool?
Java Thread pool represents a group of worker threads, which are waiting for the task to be allocated.
Threads in the thread pool are supervised by the service provider which pulls one thread from the pool 
and assign a job to it.
After completion of the given task, thread again came to the thread pool.
The size of the thread pool depends on the total number of threads kept at reserve for execution.


11. Describe acid property in transactions:

12. What is functional Dependency?

13.  What is stored procedure?
A stored procedure is a group of SQL statements that have been created and stored in the database. 
The stored procedure increases the reusability as here the code or the procedure is stored into the 
system and used again and again that makes the work easy, takes less time in processing and decreases 
the complexity of the system. So, if you have a code which you need to use again and again then save 
that code and call that code whenever it is required.





Design a configuration management system

User should be able to add configuration
User should be able to delete configuration
User should be able to search for configuration
User should be able to subscribe to Configuration So that any updates in configuration will gets notfied to user




Design an online chat
Constraints and assumptions
Assume we'll focus on the following workflows:
Text conversations only
Users
   Add a user
   Remove a user
   Update a user
   Add to a user's friends list
      Add friend request
      Approve friend request
      Reject friend request
      Remove from a user's friends list

Create a group chat
   Invite friends to a group chat
   Post a message to a group chat
Private 1-1 chat
   Invite a friend to a private chat
   Post a meesage to a private chat
No need to worry about scaling initially



'
//todays interview

1. You are a professional robber planning to rob houses along a street. Each house has a certain 
amount of money stashed, the only constraint stopping you from robbing each of them is that a
djacent houses have security systems connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police


Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


2. Given an array A[ ] of positive integers of size N, where each value represents the number 
of chocolates in a packet. Each packet can have a variable number of chocolates. There are 
M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number 
of chocolates given to a student is minimum.


Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and 
we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum 
difference between maximum and minimum packet 
sizes.



3. Design irctc , a website to book train

1. schedulate a train(search)
2. book a single seat in given train(or multiple)
3. train has-> route (stop, time)
   seat arrangement
3.5 tatkal booking 
4. month advance booking
5. Parallel seal booking
6. Cancellation -> no booking
   wrong booking


4. Bridges in a graph

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. 
For a disconnected undirected graph, definition is similar, a bridge is an edge removing which
increases number of disconnected components.'' 


5. Design a vending machine with following functionalities

-Three types of Users : User, Operator, Admin
-User can select and buy multiple items at a time. Money can be inputted multiple times 
(you will get the item if there is a time gap > 30 secs). He can also do window shopping 
(see only the prices of items and buy nothing)

-Operator can load the items and mark the items as expired if needed, gets notified if a product goes out of stock.
-Admin can own multiple vending machines, he should have a analytics report of the items 
purchased in a month. He can also change the prices directly and it should reflect in all 
the vending machines which he owns.
-Exception handling in all the edge cases


//general questions

1. How do you approach debugging an entire system of applications?

2. How have you implemented the Agile framework in your software design processes?

3. When would you consider a NoSQL design over an SQL design?

4. How have you used continuous integration and delivery to achieve business goals?

5. What project management tools have you used?

6. Talk about a project you completed successfully

7. Compare the sleep() and wait() methods in Java, including when and why you would use one vs. the other.

8. Which Design Patterns have You Used in Your Java Project? 


