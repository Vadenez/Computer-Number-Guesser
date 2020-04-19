#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;

int main()
{
    int max, min, diff, guess, sec, att, num, o;
    string com = "TO COMPUTER: ";
    string to = "Your guess was to ";
    guess = NULL;
    att = 0;
    o = 1;
    //Descirption
    cout << "This is a game where your computer will try and guess your value." << endl;
    //get max
    cout << "First, whats the Maximum Value your computer can guess: ";
    cin >> max;
    //get min
    cout << endl << "And, whats the Minimum Value: ";
    cin >> min;
    //get difference between max and min
    diff = max - min + 1;
    //comformation of sorts
    cout << "There will be " << diff << " possible values for the computer to chose from, ranging from " << min << "-" << max <<"."<< endl << endl;
    //chose a value
    cout << "What will your value be?" << endl << "Make sure its between the minimum and maximum values." << endl << "Your Value: ";
    cin >> num;
    //if out of max and min threshold
    while (max <= num || num <= min) {
        cout << "Sorry, but your value was outside your given threshold." << endl << "Another value please: ";
        cin >> num;
    }
    //time between guesses
    cout << "How long do you want the computer to wait between guesses?" << endl << "Wait time in seconds: ";
    cin >> sec;
    //stops it from being to long or being negative
    while (sec > 20 || sec < 0) {
        cout << "Sorry, but make sure your time (in seconds) is between 0 and 20." << endl << "Another value please: ";
        cin >> sec;
    }
    //converts seconds to milliseconds
    sec = sec * 1000;
    //gets first computers guess
    srand((unsigned int)time(NULL));
    guess = rand() % diff + min;
    //a while loop for guesses
    while (guess != num) {
        //stops compuer for set amount of time
        sleep_for(milliseconds(sec));
        //adds to the attempts
        att++;
        //displays attemps #
        cout << endl << "Attempt #" << att <<"."<< endl;
        cout << com << "Sorry, thats wrong." << endl;
        //gives computer the understanding if its low or high
        if (guess < num) {
            cout << com << to << "low." << endl;
            min = guess + 1;
        }
        else {
            cout << com << to << "high." << endl;
            max = guess;
        }
        //tells us the computer's guess
        cout << com<< "Your guess: "<< guess << endl;
        
        diff = max - min;
        //new guess
        srand((unsigned int)time(NULL));
        guess = rand() % diff + min;
    }

    sleep_for(milliseconds(sec));
    //if the computers correct
    cout << endl<< com << "Correct, the number was " << num << ", good job." << endl;
    //fun program ending sequence
    cout << "TO USER: Type 1 and press ENTER to end the program: ";
    num = 2;
    cin >> num;
    
    while (num != 1) {
        cout << endl << "You entered " << num << ", which is not 1" << endl;
        cout << "Type 1 then press ENTER: ";
        cin >> num;
        o++;

        while (o >= 3) {
            cout << endl << "This is attempt #" << o + 1<< ", of entering the number \"1\"" << endl;
            cout << "Waiting: ";
            cin >> num;
            o++;
            if (num == 1) {
                o = 0;
            }
            else {}
        }
    }
    //ends program
    return 0;
}
