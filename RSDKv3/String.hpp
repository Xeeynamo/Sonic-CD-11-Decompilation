#ifndef STRING_H
#define STRING_H

inline void StrCopy(char *dest, const char *src)
{
    strcpy(dest, src);
}

inline void StrAdd(char *dest, const char *src)
{
    strcpy(dest + strlen(dest), src);
}

inline bool StrComp(const char *stringA, const char *stringB)
{
    bool match    = true;
    bool finished = false;
    while (!finished) {
        if (*stringA == *stringB || *stringA == *stringB + ' ' || *stringA == *stringB - ' ') {
            if (*stringA) {
                ++stringA;
                ++stringB;
            }
            else {
                finished = true;
            }
        }
        else {
            match    = false;
            finished = true;
        }
    }
    return match;
}

inline int StrLength(const char *string)
{
    return strlen(string);
}
int FindStringToken(const char *string, const char *token, sbyte stopID);

#endif // !STRING_H
