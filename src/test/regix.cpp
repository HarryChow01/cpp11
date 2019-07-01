
#include <cstdlib>
#include <cstdio>
#include <cstring>

//判断一个正规pattern和str是否匹配
//其中?类似于.，匹配任何字符，只含有*?和普通字符
//http://zhidao.baidu.com/link?url=trAqd4aAMt3BQ9kMkG_J55fZrVwsSUehDfo809m7VyjXOrVlnnPLGJ8rNY0M0aOSgSLVDwFs2GDxpKz5VdYnsK
 
bool IsMatched(const char* pattern, const char* str);
bool IsStarMatched(int ch, const char* pattern, const char* str);


int main(int argc, char *argv[]) {
    printf("into main\n\n");
    
    //char pattern[] = "abc?ef*xy";
    //char src[] = "abcdefffxy";
    
    char pattern[] = "abc?ef*xy";
    char src[] = "abcdexy";
    
    bool isMatched = IsMatched(pattern, src);
    
    if(isMatched)
    {
        printf("Matched\n");
    } else
    {
        printf("Not Matched\n");
    }
    
    printf("\n\nreturn from main\n");

}


// matchhere: search for pattern at beginning of str
// ?match any char link . 

bool IsMatched(const char* pattern, const char* str)
{
    if (pattern[0] == '\0')
        return true;
    if (pattern[1] == '*')  //if there is a * in str, this function will return next line
        return IsStarMatched(pattern[0], pattern+2, str);
        
    if ((*str != '\0') && (pattern[0] == '?' || pattern[0] == *str))
        return IsMatched(pattern+1, str+1);
    return false;
}

// matchstar: search for c*pattern at beginning of str
bool IsStarMatched(int ch, const char* pattern, const char* str)
{
    do {   //* a * matches zero or more instances
        if (IsMatched(pattern, str))
            return true;
    } while (*str != '\0' && (*str++ == ch || ch == '?'));
    return false;
}



/*
// match: search for pattern anywhere in str
int match(char *pattern, char *str)
{
    if (pattern[0] == '^')
        return matchhere(pattern+1, str);
     do {     //must look even if string is empty
         if (matchhere(regexp, text))
             return 1;
     } while (*text++ != '\0');
    return 0;
}

 // matchhere: search for pattern at beginning of str
 int matchhere(char *pattern, char *str)
 {
    if (pattern[0] == '\0')
        return 1;
    if (pattern[1] == '*')
        return matchstar(pattern[0], pattern+2, str);

    if (pattern[0] == '$' && pattern[1] == '\0')
        return *str == '\0';
    if (*str!='\0' && (pattern[0]=='.' || pattern[0]==*str))
        return matchhere(pattern+1, str+1);
    return 0;
 }
 // matchstar: search for c*pattern at beginning of str
 int matchstar(int c, char *pattern, char *str)
 {
   do {   //* a * matches zero or more instances
       if (matchhere(pattern, str))
           return 1;
   } while (*str != '\0' && (*str++ == c || c == '.'));
   return 0;
 }

*/
 


/*
bool IsMatched(const char* pattern, const char* str)
{
    const int lenpattern = strlen(pattern);
    const int lenstr = strlen(str);
    int i = 0;
    int j = 0;
    bool ret = false;
    
    while((i < lenpattern)&&(j < lenstr))
    {
        if(pattern[i] == '?')
        {
            i++;
            j++;
        }
        else if(pattern[i] =='*')
        {
            if(i == 0)  //first char in pattern is not *
            {
                return false;
            }
            if(pattern[i - 1] =='*' || pattern[i - 1] =='?')
            {
                return false;
            }
            while( (j < lenstr) && (pattern[i - 1] == str[j]) )
            {
                j++;
            }    
            i++;    
        }
        
        else    //pattern is normall char
        {
            if(pattern[i] == str[j])
            {
                i++;
                j++;
            }
            else
            {
                return false;
            }
        }  
    }
    
    if(i >= lenpattern) //pattern is over
    {
        return true;
    }
    else    //pattern is not over, str over
    {
        while( (i < lenpattern) && (pattern[i] == '*') )
        {
            i++;
        }
        
        if(i < lenpattern)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    
    return ret;
}
*/








