#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"
#include "term_operations.h"

int main()
{
    reg_system sys{};                       // Our system parameters, in the form of a system object. See reg_system.h and reg_system.cpp for more information
    vector<course> courses;                 // A vector of all courses offered by the university. See course.h and course.cpp for more information
    vector<classroom> classrooms;           // A vector of all classrooms available to the courses. See classroom.h and classroom.cpp for more information
    vector<student> students;               // A vector of all students attending the university. See student.h and student.cpp for more information
    vector<student> graduated_students;     // WIP: A vector of all student that have graduated. The objective is to remove students from the 'students' vector when they have graduated, and store them here instead
    vector<string> FUS;                     // A vector of the course IDs recommended by the FUS for all students during a term

    sys.create("system-parameters-in.txt");     // Takes in the system parameter input file and stores the pertinent information for the system. See reg_system.h and reg_system.cpp for more information

    sys.write(cout);

    courses_read("courses.txt", courses);   // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector

    print_all_courses(cout, courses);

    classrooms_read("classrooms.txt", classrooms);  // Takes in the classroom input file and adds the classrooms available to the classrooms vector. See classroom.h and classroom.cpp for more information

    print_all_classrooms(cout, classrooms);

    students_ini(students, sys.students()); // Initializes the vector of students attending the university. See student.h and student.cpp for more information

    //print_all_students(cout, students);

    for(int i = 0; i < 2; i++) {            // this for loop simulates terms. Here is simulating 2 terms.
        for (int i = 0; i < students.size(); i++) {
            FUS.push_back(students[i].bestChoice(courses));     // Selects a course for each student to take that semester. See student.h and student.cpp for more information
        }
        for (int i = 0; i < students.size(); i++) {     // this for loop doesn't really need to exist, but it doesn't do any harm
            students[i].schedule('m');                  // Scheduling the selected course (done above) for each student and assigning it to the morning time (designated by the char 'm'). See student.h and student.cpp for more information
            students[i].complete_courses();             // Transfers all scheduled courses to the completed courses vector each student object has. See student.h and student.cpp for more information
            students[i].graduate(sys.core_courses());   // Checks if a student qualifies to graduate, and does so if the student qualifies
        }

    }

    print_all_students(cout, students);

    //time_table_creation_test_1(courses, classrooms);

    //time_table_print(courses, sys.terms_to_process());

	//for(int i = 0; i < sys.terms_to_process(); i++){

        // while( !reg_n_sched_complete):

            // Course Selection  - done^TM

            // Sample student course selection print - not done

            // Course Scheduling - done^TM

        // Building manager duties - done^TM

        // Term time table print - DONE

        // tuition processing - not done (callum)

        // courses taking by student during the term (must be sorted according to the number of taken courses in the semester) - not done

        // term_completed() - not done

        // Graduated student by this term - not done
    //}

    return 0;
}
