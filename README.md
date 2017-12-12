# Saturday-University-Project
School Project - Creating a Registration System for an University

Project Members	(responsibilities):
Manuel	(Input files reading and System initialization, Code organization, System logs creation, Course selection algorithm, Building manager processes)
Ibrahim	(Course Scheduling, Building manager processes)
Callum	(Course selection algorithm, Course Scheduling, Building manager processes)

This is a school project for our System Analysis course. The purpose was to create a system that processes the course registration of a determined number of students,
using a pool of courses given to us, and match each course to a classroom in order to optimize the amount of students taking courses during the term.
This system runs through a pre-determined amount of terms (assuming that every student passed the courses he/she took), and creates certain logs of each term as its output.

The system's specifications are as follow:

  1. There are no new students registering after the first term;
  2. There are only two time slots that courses can be taken - Morning & Afternoon;
  3. Students can only take two courses per term, on per time slot;
  4. Students cannot retake a course;
  5. Student must have all pre-requisite courses completed in order to take a course with those pre-requisite courses;
  6. Courses are scheduled one by one according the amount of students that registered to it;
  7. After a course is scheduled to a time slot, student then go through the course selection process again. This loop is done until either all courses have been scheduled, or all eligble students have selected courses;
  8. In order for a course to have a classroom assgined to it for the term, it must have more than three students registered to it. If a course does not satisfy this requirement, it ceases to be scheduled for the term;
  9. the number of students in the course cannot exceed the vacancy of the classroom assigned to the course. If it does, students are deregistered from the course;
 10. If there are more courses that have been scheduled than there are classrooms, then the courses with the least amount of registrations cease to be scheduled;
 11. The tuition for each course is the same for every course, and is counted in units of tuition (not monetary value);
 12. There is a student number (x), to which we need to sample the course selection made for the student during a specific term (y).
 
The system logs are as followed:

 A. The time table of each term processed, which includes the courses taken in the term, their assigned time slot, the room assigned, and the amount of students taking the course;
 B. The tuition paid for each term processed;
 C. The list of graduated students as terms are processed (and the total count);
 D. The courses taken by each student for every term processed, ordered by the amount of courses each student takes during the term;
 E. The course selections made for student x during term y.
 
 Note:
 * The "building manager" refers to the processes detailed in specifications numbered 8. to 10.