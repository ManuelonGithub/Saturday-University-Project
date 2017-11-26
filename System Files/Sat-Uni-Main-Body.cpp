#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"
#include "term_operations.h"

int main()
{
    reg_system sys{};
    vector<course> courses;
    vector<classroom> classrooms;
    vector<student> students;
    vector<string> FUS;

    sys.create("system-parameters-in.txt");

    //sys.write(cout);

    courses_read("courses.txt", courses, sys.courses());

    //print_all_courses(cout, courses);

    classrooms_read("classrooms.txt", classrooms);

    //print_all_classrooms(cout, classrooms);

    students_ini(students, sys.students());

    //time_table_creation_test_1(courses, classrooms);

    //time_table_print(courses, sys.terms_to_process());

    for (int i = 0; i < 20; i++) {
        FUS.push_back(students[i].bestChoice(courses));
    }

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
