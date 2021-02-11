#include "Serializer.hpp"
#include <unistd.h>

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &) {}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &) { return *this; }

void *Serializer::serialize()
{
    std::srand( (unsigned) time(NULL) * getpid());
    struct RawData *serializedData = new struct RawData;
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 8; i++)
    {
        serializedData->s1[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        serializedData->s2[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    serializedData->n = rand();
    return serializedData;
}

Data *Serializer::deserialize(void *raw)
{
    RawData *tempRaw = reinterpret_cast<RawData*>(raw);
    Data *temp = new struct Data;
    temp->s1 = std::string(tempRaw->s1, 8);
    temp->s2 = std::string(tempRaw->s2, 8);
    temp->n = tempRaw->n;
    return temp;
}