#include "PassengerEntry.h"

PassengerEntry::PassengerEntry(int _id,
                               int _age,
                               float _fare,
                               int _sex,
                               int _sibsp,
                               int _parch,
                               int _pclass,
                               int _embarked,
                               int _survived)
    : id(_id),
      age(_age),
      fare(_fare),
      sex(_sex),
      sibsp(_sibsp),
      parch(_parch),
      pclass(_pclass),
      embarked(_embarked),
      survived(_survived)
{
}