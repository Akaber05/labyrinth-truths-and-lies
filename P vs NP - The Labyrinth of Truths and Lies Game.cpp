/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>


#include <vector>

using namespace std;

string randQuestions() {
    vector<string> questions = {
                                "What Continent was Akaber born in?", 
                                "How many times did Lucky graduate highschool?",
                                "When did Umaya learn how to swim?",
                                "How many cats does Maria have?",
                                "How many Years did Anna swim competetively?",
                                "What country did Renee visit during the summer?",
                                "What country was Tayfa born in?",
                                "How many language courses did Nura take?",
                                "Why did Nura quite her job?",
                                "How many brothers does Anna have?"
    };
    srand(time(NULL));
    int randomIndex = rand() % questions.size();
    return questions[randomIndex];
}

string trueAnswers(string question) {
    vector<string>answers = {
                            "Europe",
                            "Twice",
                            "Never",
                            "3",
                            "4",
                            "None",
                            "USA",
                            "6",
                            "She was going to get fired",
                            "0"
                            
    };
    if (question == "What Continent was Akaber born in?") {
        return answers[0];
    }
    else if (question == "How many times did Lucky graduate highschool?") {
        return answers[1];
    }
    else if (question == "When did Umaya learn how to swim?") {
        return answers[2];
    }
    else if (question == "How many cats does Maria have?"){
        return answers[3];
    }
    else if (question == "How many Years did Anna swim competetively?") {
        return answers[4];
    }
    else if (question == "What country did Renee visit during the summer?") {
        return answers[5];
    }
    else if (question == "What country was Tayfa born in?") {
        return answers[6];
    }
    else if (question == "How many language courses did Nura take?") {
        return answers[7];
    }
    else if (question == "Why did Nura quite her job?") {
        return answers[8];
    }
    else if (question == "How many brothers does Anna have?") {
        return answers[9];
    }
    return 0;
}

string LieAnswers(string question) {
    vector<string>answers = {
                            "North America",
                            "Once",
                            "2 years ago",
                            "10",
                            "13",
                            "France",
                            "Dubai",
                            "1",
                            "She wanted to focus on school",
                            "3"
                            
    };
    if (question == "What Continent was Akaber born in?") {
        return answers[0];
    }
    else if (question == "How many times did Lucky graduate highschool?") {
        return answers[1];
    }
    else if (question == "When did Umaya learn how to swim?") {
        return answers[2];
    }
    else if (question == "How many cats does Maria have?"){
        return answers[3];
    }
    else if (question == "How many Years did Anna swim competetively?") {
        return answers[4];
    }
    else if (question == "What country did Renee visit during the summer?") {
        return answers[5];
    }
    else if (question == "What country was Tayfa born in?") {
        return answers[6];
    }
    else if (question == "How many language courses did Nura take?") {
        return answers[7];
    }
    else if (question == "Why did Nura quite her job?") {
        return answers[8];
    }
    else if (question == "How many brothers does Anna have?") {
        return answers[9];
    }
    return 0;
    
}

int main()
{
    int choice=0;
    string yN_ans;
    int numCorrect=0;
    int win=6;
    int tries=0;
    string question;
    string answer;
    int guess;
    cout<<"Welcome to the Truth or Lie Labrynth Game!\nFind your way by asking the sentinels questions. Sometimes they tell the truth and other times they don't.\nCan you guess how many questions it will take you to answer 6 correctly?. Good Luck!\n\n";
    

   cout<<"How many questions do you think it will take you to guess 6 questions correctly...?: ";
   cin>>guess;
    
    while (numCorrect<win){
        cout<<"\nThere are paths with sentinels. Choose a sentinel to question (1-10): ";
        cin>>choice;
        if (choice <1 || choice >10) {
            cout<<"\nChoose a sentinel between 1-10: ";
            cin>>choice;
        }
        
        int index = choice-1;
        vector<bool>truthful(10);
        truthful[index] =rand()%2;
        
        question=randQuestions();
        
        if(truthful[index]) {
            answer= trueAnswers(question);
        }
        else {
            answer= LieAnswers(question);
        }
        
        cout<<"\nYou ask the sentinel: "<<question<<endl;
        cout<<"\nThe sentinel responds: " <<answer<<endl<<endl;
        cout<<"\nDo you think the sentinel is telling the truth? (yes/no): ";
        cin>>yN_ans;
        
        if(yN_ans!="yes" && yN_ans!="no" && yN_ans!="YES" && yN_ans!="NO"){
            cout<<"Your input was invalid.Do you think the sentinel is telling the truth? (yes/no): ";
            cin>>yN_ans;
        }
        bool userGuess = (yN_ans=="yes");
        if(userGuess==truthful[index]) {
            cout<<"\nYou detected the truth/lies correctly!\n";
            numCorrect+=1;
        }
        else {
            cout<<"\nWrong detection. Try again!\n";
        }
        
       tries+=1; 
    }
    if(tries<=guess){
        cout<<"\nCongratulations you have confidently guessed that you can identify 6 lies/truths with "<< tries<<" questions asked!!!";
    }
    else {
        cout<<"\nOh no, you were too confident and have lost the game :( \n\nIt took you "<<tries<<" tries to get 6 questions correct.";
    }

    return 0;
}