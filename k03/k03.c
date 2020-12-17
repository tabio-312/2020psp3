#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
int start=0;
int pos=0;
int keylen;
int textlen;
int i;

textlen = strlen(text);
keylen =strlen(key);
for(start=0; start < textlen; start++)
{
    for(i=0; i<keylen; i++)
    {
        if(text[start+i]==key[pos])
        {
            pos++;
            if(keylen==pos){
                return &text[start];
            }
        }else
        {
            break;
        }
    }
    pos = 0;
}
return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
char table[ALPHABET_LEN];
int n=0;
int index;
int keylen;
int textlen;
int index_before;
int pos;

index = strlen(key)-1;
keylen = strlen(key);
pos = keylen - 1;
textlen = strlen(text);
while(n <= ALPHABET_LEN)
{
    table[n] = keylen;
    n++;
}
n = 0;
while(n<keylen)
{
    table[(int)key[n]] = keylen -1-n;
    n++;
}

while(index <= textlen)
{
    while(pos >= 0)
    {
        if(text[index] == key[pos])
        {
            if(pos == 0)
            {
                return text + index;
            }
            index--;
            pos--;
        }
        else{
            pos = keylen-1;
            break;
        }
    }
    index_before=index;
    index = index + table[(int)text[index]];
    if(index_before >= index)
    {
        index = index_before + 1;
    }
}
return NULL;

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}