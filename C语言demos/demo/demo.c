#include <stdio.h>
#include "ocilib.h"

void err_handler(OCI_Error *err)
{
    printf(
            "code  : ORA-%05i\n"
            "msg   : %s\n"
            "sql   : %s\n",
            OCI_ErrorGetOCICode(err),
            OCI_ErrorGetString(err),
            OCI_GetSql(OCI_ErrorGetStatement(err))
    );
}

int main(int argc, _TCHAR* argv[])
{

    OCI_Connection* cn;
    OCI_Statement* st;
    OCI_Resultset* rs;


    OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);

    cn  = OCI_ConnectionCreate("192.168.1.152:1521/TEST", "system", "123456", OCI_SESSION_DEFAULT);

    if(cn == NULL){
        err_handler(OCI_GetLastError());
        printf("%i",OCI_GetVersionServer(cn));
        printf("连接失败！\n");
    }
    st  = OCI_StatementCreate(cn);

    OCI_ExecuteStmt(st, "select id,age from web_user");

    rs = OCI_GetResultset(st);

    while (OCI_FetchNext(rs)){
        printf("code: %i, name %s\n", OCI_GetInt(rs, 1)  , OCI_GetString(rs, 2));
    }

    printf("\n%d row(s) fetched\n", OCI_GetRowCount(rs));


    OCI_Cleanup();


    char a[20];
    gets(a);

    return EXIT_SUCCESS;
}

