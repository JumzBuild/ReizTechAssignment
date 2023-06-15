#include <iostream>
#include <cmath>
using namespace std;

double calculateAngle(int hours, int minutes)
{
    // Calculate the angles for the hour and minute hands
    double hourAngle = (hours % 12 + minutes / 60.0) * 30;
    double minuteAngle = minutes * 6;

    // Calculate the absolute difference between the angles
    double angle = abs(hourAngle - minuteAngle);

    // Get the lesser angle (considering both clockwise and counterclockwise rotations)
    angle = min(angle, 360 - angle);

    return angle;
}

int main()
{
    int hours, minutes;
    char retry;

    try_again:

    cout << "Enter the hours (0-12): ";
    cin >> hours;
      if (hours >= 0 && hours <= 12)
      {
        minute:
        cout << "Enter the minutes (0-59): ";
        cin >> minutes;

         if (minutes >= 0 && minutes <= 59)
         {
            double angle = calculateAngle(hours, minutes);
            cout << "The lesser angle between the hour and minute hands is " << angle << " degrees." << endl;
            cout << "\n\nWould like to try again? \nPress Y for Yes, and any key for No" << endl;
            cin>>retry;
            if( retry == 'Y'|| retry =='y')
            {
            	system("cls");
                goto try_again;
            }
            else
            {
                 cout << "Terminating program..." << endl;

            }
         }

        else
        {
            cout << "Invalid input! Please enter numbers from 0-59" << endl;
            goto minute;

        }

      }

      else
      {
        cout << "Invalid input! Please enter numbers from 0 and 12" << endl;
        goto try_again;
      }

    return 0;
}
