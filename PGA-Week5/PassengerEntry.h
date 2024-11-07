#pragma once

// Passenger Entry to store a full row of data
class PassengerEntry
{
public:
    PassengerEntry(int _id,
                   int _age,
                   float _fare,
                   int _sex,
                   int _sibsp,
                   int _parch,
                   int _pclass,
                   int _embarked,
                   int _survived);

    int id;
    int age;
    float fare;
    int sex;
    int sibsp;
    int parch;
    int pclass;
    int embarked;
    int survived;
};
