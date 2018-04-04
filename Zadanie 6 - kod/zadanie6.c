# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <string.h>

int main(int argc, char *argv[]) {

  if (isatty(1)) {

    char buf[BUFSIZ];
    fgets(buf, sizeof buf, stdin);

    if (buf[strlen(buf)-1] == '\n') { // Reading from a buffer, expecting to get the numberOfColorsSupported from pipe
      int numberOfColorsSupported = atoi(buf);

      for(int i=0; i<numberOfColorsSupported; i++)
        printf("\033[38;5;%dm%d) Hello, world!\n", i, i);
    }
    else {
        fprintf(stderr, "Error: The line was truncuated.");
    }
  }
  else {
    fprintf(stderr, "Error: The command was not run in the proper terminal instance.");
  }
  return 0;
}
