#include <fstream>
#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"
#include "term_operations.h"
#include <ctime>

int main()
{
    vector<classroom> classrooms;           // A vector of all classrooms available to the courses. See classroom.h and classroom.cpp for more information
    vector<student> students;               // A vector of all students attending the university. See student.h and student.cpp for more information
    vector<course> courses;                 // A vector of all courses offered by the university. See course.h and course.cpp for more information
    vector<string> FUS;                     // A vector of the course IDs recommended by the FUS for all students during a term
    reg_system sys{};                       // Our system parameters, in the form of a system object. See reg_system.h and reg_system.cpp for more information

    sys.create("input_para.txt");                   // Takes in the system parameter input file and stores the pertinent information for the system. See reg_system.h and reg_system.cpp for more information
    students_ini(students, sys.students());         // Initializes the vector of students attending the university. See student.h and student.cpp for more information
    courses_read("input_course.txt", courses);      // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector
    classrooms_read("input_room.txt", classrooms);  // Takes in the classroom input file and adds the classrooms available to the classrooms vector. See classroom.h and classroom.cpp for more information

    ofstream graduation_status("graduation status.txt");
    ofstream term_time_table("Term Time Tables.txt");
    ofstream student_courses("Student Courses.txt");
    ofstream sampling("sampled data.txt");
    ofstream tuition_out("Tuition.txt");


    srand(time(NULL));
    bool done_scheduling = false;
    int term_tuition, graduated_students;
    unsigned long max_iterations = 2*(classrooms.size()-1);

    sampling << "the courses selected for student B" << sys.Sample_Student() << " for term " << sys.Sample_Term() << " are: ";

    for(int term = 0; term < sys.terms_to_process(); term++) {
        bool time_slot_toggle = true;           // true is morning, false is afternoon
        graduated_students = 0;
        graduation_status << "Students that graduated on term " << (term+1) << ":\n\n";

        for (int k = 0; k < max_iterations; k++) {
            FUS.clear();
            for (int i=0; i < students.size(); i++) {
                FUS.push_back(course_selection(courses, students[i], time_slot_toggle)); // FUS gives students suggestion
                if(((term+1) == sys.Sample_Term()) && (i == sys.Sample_Student())) {
                    if(FUS[i] != "No") {
                        sampling << FUS[i] << ", ";
                    }
                }
            }
            done_scheduling = Scheduler(FUS, courses, time_slot_toggle, students);//Determine what class should be scheduled and when
            time_slot_toggle = !time_slot_toggle;

            if(done_scheduling) { break; }
        }

        term_tuition = building_manager(courses, students, classrooms, term, term_time_table);
        tuition_out << "The amount of tuition paid for term "<< (term+1) << " is " << term_tuition <<endl;

        student_courses << "Scheduled courses for students in term " << (term+1) << ":\n\n";
        print_attendance(student_courses, students);

        for (int i=0; i< students.size(); i++){
            students[i].complete_courses();
            students[i].graduate(sys.core_courses());
            if(students[i].graduated()) {
                graduated_students++;
                students[i].graduated_write(graduation_status, term);
            }
        }

        graduation_status << "Total amount of graduated students after " << (term+1) << " terms: " << graduated_students << "\n\n\n";

        for (int i=0; i< courses.size(); i++) {
            courses[i].clear_sch();
        }
    }

    graduation_status.close();
    student_courses.close();
    term_time_table.close();
    tuition_out.close();
    sampling.close();
    return 0;
}
