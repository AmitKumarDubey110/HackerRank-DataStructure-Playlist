#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    bool isEOW;
    int count;
    struct node *letters[26];
} Trie;
Trie *createNode()
{
    int i;
    Trie *temp=malloc(sizeof(Trie));
    temp->isEOW=false;
    temp->count=0;
    for(i=0; i<26; i++)
    {
        temp->letters[i]=NULL;
    }
    return temp;
}
Trie *insert(Trie *root,char *name)
{
    int i;
    Trie *temp=root;
    for(i=0; name[i]!='\0'; i++)
    {
        if(root->letters[name[i]-'a']==NULL)
            root->letters[name[i]-'a']=createNode();
        root=root->letters[name[i]-'a'];
        root->count++;
    }
    root->isEOW=true;
    return temp;
}
/*int countNames(Trie *root)
{
    int i,count=0;
    if(root->isEOW)
        count++;
    for(i=0; i<26; i++)
    {
        if(root->letters[i])
            count=count+countNames(root->letters[i]);
    }
    return count;
}*/
int main()
{

    int i;
    long n;
    Trie* root=createNode();
    scanf("%ld",&n);
    char a[5],name[22];
    while(n--)
    {
        scanf("%s",a);
        scanf(" %s",name);
        if(strcmp(a,"add")==0)
            root= insert(root,name);
        else if(strcmp(a,"find")==0)
        {
            Trie *temp=root;
            for(i=0; i<strlen(name); i++)
            {
                temp=temp->letters[name[i]-'a'];
                if(!temp)
                {
                    printf("0\n");
                    break;
                }
            }
            if(i==strlen(name))
                printf("%d\n",temp->count);
        }
    }
    return 0;
}
