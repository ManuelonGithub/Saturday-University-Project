#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"
#include "term_operations.h"

int main()
{
    srand(time(NULL));
    reg_system sys{};                       // Our system parameters, in the form of a system object. See reg_system.h and reg_system.cpp for more information
    vector<course> courses;                 // A vector of all courses offered by the university. See course.h and course.cpp for more information
    vector<classroom> classrooms;           // A vector of all classrooms available to the courses. See classroom.h and classroom.cpp for more information
    vector<student> students;               // A vector of all students attending the university. See student.h and student.cpp for more information
    vector<student> graduated_students;     // WIP: A vector of all student that have graduated. The objective is to remove students from the 'students' vector when they have graduated, and store them here instead
    vector<string> FUS;                     // A vector of the course IDs recommended by the FUS for all students during a term
    vector<scheduled_course> sched_courses;

    sys.create("system-parameters-in.txt");         // Takes in the system parameter input file and stores the pertinent information for the system. See reg_system.h and reg_system.cpp for more information
    courses_read("courses.txt", courses);           // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector
    classrooms_read("classrooms.txt", classrooms);  // Takes in the classroom input file and adds the classrooms available to the classrooms vector. See classroom.h and classroom.cpp for more information
    students_ini(students, sys.students());         // Initializes the vector of students attending the university. See student.h and student.cpp for more information
    
    unsigned long iteration = 2*(classrooms.size()-1);

    for (int i=0; i< sys.terms_to_process(); i++){
        sched_courses.clear();
        bool time_slot_toggle = true;           // true is morning, false is afternoon
    for (int k = 0; k < iteration; k++)
    {
        cout << "Iteration number: " << k << endl;
        FUS.clear();

        for (int i=0; i < students.size(); i++) {
            FUS.push_back(course_selection(courses, students[i], time_slot_toggle)); // FUS gives students suggestion
            students[i].set_selected_course(FUS[i]); // save student suggestion in the class
        }

        Scheduler(FUS, courses, time_slot_toggle, students, sched_courses);//Determine what class should be scheduled and when
        print_attendance(FUS, courses, students, classrooms);
        time_slot_toggle = !time_slot_toggle; // this is stupid
    }

    for(int i = 0; i < sched_courses.size(); i++) {
        sched_courses[i].write(cout);
    }
    for (int i=0; i< students.size(); i++){
            students[i].complete_courses();
            students[i].graduate(sys.core_courses());
        }
        
    for (int i=0; i< courses.size(); i++ ){
            courses[i].clear_sch();
        }
        
    }
    /*
    cout << "Room     Morning course/size    Afternoon course/size" << endl;
    for (int i=0; i < classrooms.size(); i++){
        classrooms[i].printCourses();
    }
    */

    //for(int i = 0; i < sys.terms_to_process(); i++){

    // while( !reg_n_sched_complete):

    // Course Selection  - done^TM

    // Sample student course selection print - not done

    // Course Scheduling - done^TM

    // Building manager duties - done^TM

    // Term time table print - DONE

    // tuition processing - not done (callum)

    //  tution = calculateTuition(courses);

    // courses taking by student during the term (must be sorted according to the number of taken courses in the semester) - not done

    // term_completed() - not done

    // Graduated student by this term - not done
    //}

    return 0;
}
