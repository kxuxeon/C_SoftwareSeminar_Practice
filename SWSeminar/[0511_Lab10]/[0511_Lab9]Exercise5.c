#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
    char name[32];
    char phone[32];
} CONTACT;

CONTACT* AllocateBooks(int count);
void InputContacts(CONTACT* contacts, int count);
void PrintContacts(const CONTACT* contacts, int count);

int main(void){
    CONTACT* contacts = NULL;
    int cnt = 0;

    printf("저장할 연락처의 개수 : ");
    scanf("%d", &cnt);
    while( getchar() != '\n' );

    contacts = AllocateContacts(cnt);
    if( contacts == NULL )
        return -1;

    InputContacts(contacts, cnt);
    PrintContacts(contacts, cnt);

    free(contacts);
    contacts = NULL;

    return 0;
}

CONTACT* AllocateBooks(int count){
    CONTACT *result = NULL;
    result = (CONTACT*)malloc(sizeof(CONTACT)*count);
    if( result == NULL ) printf("동적 메모리 할당 실패\n");
    else memset(result, 0, sizeof(CONTACT)*count);
    return result;
}

void InputContacts(CONTACT* contacts, int count){
    for(int i = 0; i < count; i++ )
    {
        printf("이    름 : ");
        gets(contacts[i].name);
        printf("전화번호 : ");
        gets(contacts[i].phone);
    }
}

void PrintContacts(const CONTACT* contacts, int count){
    printf(" --- 전체 연락처 목록 ---\n");
    for(int i = 0; i < count; i++ ){
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}