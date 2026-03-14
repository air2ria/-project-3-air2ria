Project 3: Rotations & Data Structures
Project Overview
In previous projects, we built the Vector3D class to represent points and directions in 3D
space. We have also created a Rotation class with three subclasses, representing a
rotation in several forms: Euler angles (roll, pitch, yaw), Axis-Angle (a direction vector and
a rotation angle), and Quaternions (a four-component representation).
You are provided with an implementation of ArrayBag, an array-based container
implementing the ADT Bag. Your job is to add equality comparisons to each rotation class
and the Vector3D class, and build a RotationRegistry that manages a collection of
rotations using the ArrayBag.
Project Setup
Accept the project on GitHub Classroom through this link:
https://classroom.github.com/a/krwgFpyV.
Note: If prompted, please select your name from the roster list.
Upon accepting the assignment, a repository will be automatically made for you. In it, you
will find starter code and files provided. You will build your project in this repository, push
changes to it, and submit this repository on Gradescope.
● Unsure about the workflow? https://www.youtube.com/watch?v=AHDCokfgcSo.
● Beginner to Git? https://www.youtube.com/watch?v=MJUJ4wbFm_A.
Note: Make sure to run make clean before committing your changes. You
should never see .o files in your version control.
Task 1: Overload Equality Operators
The == operator lets us check if two objects of the same type are "equal." This is essential to
our ArrayBag; it relies on == comparisons to search for, count, and remove items. Without
defining it, the bag has no way to compare its elements.
You will overload the equality operator for the following four classes: Vector3D,
EulerRotation, AxisAngleRotation, and QuaternionRotation. It allows up to use
the == to compare rotations, as we would with integers or strings.
Because we are working with floating-point values, you should use an epsilon tolerance
rather than exact equality. We're essentially declaring how much error we will tolerate.
Definition: two doubles a and b are considered equal if:
| a − b | < ε
where epsilon, ε = 0.001 .
Hint: The std::abs() function from the cmath header computes the absolute
value of a number.
Vector3D Equality Operator
/**
* @param other: A const-ref to the Vector3D to compare with.
* @return: True if all components (x, y, z) are equal within epsilon tolerance, false otherwise.
*/
operator==
EulerRotation Equality Operator
/**
* @param other: A const-ref to the EulerRotation to compare with.
* @return: True if roll, pitch, and yaw are equal within epsilon tolerance, false otherwise.
*/
operator==
AxisAngleRotation Equality Operator
/**
* @param other: A const-ref to the AxisAngleRotation to compare with.
* @return: True if both the axis and angle are equal, false otherwise.
* @note: Use the Vector3D equality operator to compare the axis, and epsilon tolerance for
the angle.
*/
operator==
QuaternionRotation Equality Operator
/**
* @param other: A const-ref to the QuaternionRotation to compare with.
* @return: True if all components (w, x, y, z) are equal within epsilon tolerance, false
otherwise.
*/
operator==
Hint: Should these functions be marked const? Will the function modify the
class object in any way?
Task 2: Implement RotationRegistry
Since you have a working ArrayBag and equality operators for Rotation subclasses, you
will create the RotationRegistry class. This class acts as a container that manages a
collection of Rotation objects using the ArrayBag.
The RotationRegistry class should publicly inherit from ArrayBag<Rotation*>. It
stores pointers to Rotation objects, allowing it to hold any of the three rotation subclasses
polymorphically.
Note: Recall that a publicly-derived class inherits all public and protected
members from its base class. The RotationRegistry will therefore have
access to all of ArrayBag's functionality (e.g. add, remove, toVector,
getCurrentSize, etc.).
RotationRegistry Constructor
/**
* @post: Initializes the RotationRegistry as an empty ArrayBag of Rotation pointers.
*/
RotationRegistry
Hint: Use the base class initializer in the constructor's initializer list. See Project
1 Project Specifications if you don't know what that is.
RotationRegistry Public Member Functions
● addRotation
/**
* @param rotation: A pointer to a Rotation object.
* @return: True if the rotation was successfully added, false otherwise.
* @post: Adds a rotation to the registry.
*/
addRotation
Hint: You may find a function from ArrayBag helpful.
● countQuaternions
/**
* @return: The count of QuaternionRotation objects in the registry.
*/
countQuaternions
● getAverageMagnitude
/**
* @return: The average magnitude of the axes in all AxisAngleRotation objects in the
registry.
* Returns 0.0 if no AxisAngleRotations exist.
*/
getAverageMagnitude
Hint: You will need to use dynamic_cast to safely downcast from Rotation*
to AxisAngleRotation*, so you can access the getAxis() function.
Step 4: Local Testing
There's something to keep in mind about this project. It isn't compiled exactly the same as
the previous two projects. We have a templated class: ArrayBag.
As mentioned above, templated classes are compiled a bit differently than you may be used
to. Implementation files (.cpp) are included at the bottom of the header file (.hpp).
Templates are only generated when instantiated, and the compiler must see the full definition
at the point of use.
The key idea: do not compile the template implementation file separately
Makefile
Unlike previous projects, we have not provided a fully working Makefile. You must figure out
which .cpp files need to be compiled and list them there yourself.
Open your Makefile and locate the SOURCES line:
# [TO-DO] List every .cpp file that should be compiled as its own object file.
#
# Example:
# SOURCES = A.cpp B.cpp ...
SOURCES =
Fill in SOURCES with every .cpp file that should be compiled as its own object file.
Note: Do NOT include main.cpp in SOURCES. The Makefile already handles
main.cpp separately.
For your reference, the Makefile comes with the following commands:
● make or make all: Compile the project, only recompiling modified source code.
● make clean: Delete all object files (.o) and executables (main).
● make rebuild: Freshly recompile the entire project from scratch.
○ Equivalent to make clean && make.
Submission Details
You will submit your solution to Gradescope through GitHub Classroom.
The following files must be submitted:
● Vector3D.hpp
● Vector3D.cpp
● EulerRotation.hpp
● EulerRotation.cpp
● AxisAngleRotation.hpp
● AxisAngleRotation.cpp
● QuaternionRotation.hpp
● QuaternionRotation.cpp
● RotationRegistry.hpp
● RotationRegistry.cpp
Although Gradescope allows multiple submissions, it is NOT a platform for testing and/or
debugging, and it should not be used for that purpose.
You MUST test and debug your program locally. This means creating your own tests and
ensuring your project behaves as expected. To help prevent over-reliance on Gradescope
for testing, only 5 submissions per day will be allowed.
Grading Rubric
● Correctness (85%): The program behaves as defined by the project specifications.
Your points are determined by Gradescope unit testing.
● Documentation (15%): Provide function preambles in .hpp AND .cpp files, in the
@pre, @param, @post format.
● Extra Credit (5%): To encourage students to begin projects early, we will award extra
credit to students who get their project to compile within the first 3 days.
○ To compile quickly, you should stub your entire project. This means defining
your functions but implementing them with some dummy code to temporarily
satisfy compilers. This way, you ensure you have the right interface before
implementing. Go to TA hours for guidance with this.
Authors: Tedd Lee, Prof. Wole
