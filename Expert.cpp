#include <bits/stdc++.h>
using namespace std;

class expert_system {
    vector<string> symptoms;
    struct Rule {
        string category;
        vector<string> symptoms;
        string diseases;
    };
    vector<Rule> rule;

    public:
    expert_system() {
        symptoms = {"Nausea", "Cough", "Sore Throat", "Headache", "Fever", "Dizziness"};

        rule = {
            {"Respiratory", {"Fever", "Cough", "Sore Throat"}, "Common Cold"},
            {"Respiratory", {"Fever", "Cough", "Headache"}, "Flu"},
            {"Respiratory", {"Fever", "Sore Throat"}, "Strep Throat"},
            {"Neurological", {"Headache"}, "Migraine"},
            {"Neurological", {"Dizziness", "Nausea"}, "Vertigo"}
        };
    }

    vector<string> user_input();
    void diagnose();
    void display(vector<string> posiible_disease, vector<string> category_disease);

};

vector<string> expert_system :: user_input() {
    vector<string> user_symtoms;

    for(int i = 0; i < symptoms.size(); i++) {
        char c;
        cout<<"Do you have "<<symptoms[i]<<" (y/n):";
        cin>>c;
        if(c == 'y') {
            user_symtoms.push_back(symptoms[i]);
        }
    }

    return user_symtoms;
}

void expert_system :: diagnose() {
    vector<string> user_symptoms = user_input();
    vector<string> possible_disease;
    vector<string> category_disease;

    for(int i = 0; i < rule.size(); i++) {
        bool match = true;
        for(int j = 0; j < rule[i].symptoms.size(); j++) {
            if(find(user_symptoms.begin(), user_symptoms.end(), rule[i].symptoms[j]) == user_symptoms.end()) {
                match = false;
                break;
            }
        }

        if(match) {
            possible_disease.push_back(rule[i].diseases);
            category_disease.push_back(rule[i].category);
        }
    }

    display(possible_disease, category_disease);
}

void expert_system :: display(vector<string> possible_disease, vector<string> category_disease) {
    if(!possible_disease.empty()) {
        const char separator = ' ';
        const int nameWidth = 30;

        cout<<left<<setw(nameWidth)<<setfill(separator)<<"Disease";
        cout<<left<<setw(nameWidth)<<setfill(separator)<<"Category"<<endl;

        for(int i = 0; i < possible_disease.size(); i++) {
            cout<<left<<setw(nameWidth)<<setfill(separator)<<possible_disease[i];
            cout<<left<<setw(nameWidth)<<setfill(separator)<<category_disease[i]<<endl;
        }
    } 
    else {
        cout<<"No matching disease"<<endl;
    }
}

int main() {
    expert_system es;
    es.diagnose();

    return 0;
}