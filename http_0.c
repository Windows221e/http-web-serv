#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <netinet/in.h>

void sendwebhook(const char *webhookURL, const char *message) {
         
         // add curl later to send with webhook?
}

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        AF_INET,
        0x901f, // for port 8080 we get the hex code hex(8080)
        0,
    };
    bind(s, (struct sockaddr *)&addr, sizeof(addr));
    listen(s, 10);
// binds the address?
    int client = accept(s, 0, 0);
// client accepting/waiting
    char buffer[250] = {0};
// creates buffer with 250 size
    recv(client, buffer, 250, 0);


// GET /file.html....
    char *f = buffer + 5;
    char *space_pos = strchr(f, ' ');
    if (space_pos != NULL) {
        *space_pos = '\0'; // String should be null-terminated at the space position.
    }


    int opened_f = open(f, O_RDONLY);
    sendfile(client, opened_f, 0, 250);
// closes them all ofc
    close(opened_f);
    close(client);
    close(s);

    return 0;
}


