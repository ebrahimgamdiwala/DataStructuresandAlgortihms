#include <iostream>
using namespace std;

// Hybrid Inheritance : 
//    Teacher         SportsCoach
//       ↓                  ↓
// SubjectTeacher         [Multiple]
//         \               /
//          \             /
//              Student

// Base class
class Teacher {
public:
    void teach() {
        cout << "Teacher: Teaching basics of science.\n";
    }
};

// Derived from Teacher (Multilevel Inheritance)
class SubjectTeacher : public Teacher {
public:
    void teachSubject() {
        cout << "SubjectTeacher: Specializing in Physics.\n";
    }
};

// Independent base class
class SportsCoach {
public:
    void coach() {
        cout << "SportsCoach: Coaching football.\n";
    }
};

// Derived from both SubjectTeacher and SportsCoach (Hybrid Inheritance)
class Student : public SubjectTeacher, public SportsCoach {
public:
    void learn() {
        cout << "Student: Learning from both academics and sports.\n";
    }
};

int main() {
    Student s;

    // Accessing methods from multiple inheritance paths
    s.teach();        // From Teacher (via SubjectTeacher)
    s.teachSubject(); // From SubjectTeacher
    s.coach();        // From SportsCoach
    s.learn();        // From Student

    return 0;
}
