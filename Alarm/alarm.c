#include <stdio.h>
#include <string.h>
// atoi() function - string to integer
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// Music
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


void kickstart(char argv[]) {
	// Prints whats going on
	printf("Alarm set for: %s\n", argv);

	char argstr[8];

    // Copy command line args into string
	strncpy(argstr, argv, sizeof(argstr));

	// get the hour, min, sec from the args given
	char argslist[3][3];
	char * token = strtok(argstr, ":");  // Get the first token

	// Extracting the other tokens
	int i = 0;
	while (token != NULL) {
		// Assigning each token into a list
		strcpy(argslist[i], token);
		i++;
		token = strtok(NULL, ":");  // Get the remaining tokens (Returns NULL when done)
	}

	// Assigning hour, min, sec to the value of the array
	int hour, min, sec;
	hour = atoi(argslist[0]);
	min  = atoi(argslist[1]);
	sec  = atoi(argslist[2]);

	// Converting all of it into seconds
	// Watch and learn
	hour = hour * 60;
	min = hour + min;
	min = min * 60;
	sec = min + sec;

	while (sec > 0) {
		// Format the time
		time_t seconds = sec;
		char buffer[100];
		strftime(buffer, sizeof(buffer), "%H:%M:%S", gmtime(&seconds));  // Formate to 00:00:00
		printf("\r%s", buffer); // Formated time
		fflush(stdout);
		// Reduce by 1
		--sec;
		sleep(1);
	}
	printf("\n");
}

// SDL_Music stuff
// Sadly i copied this bit from chatgpt
int playback() {
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! Error: %s\n", Mix_GetError());
		return 1;
	}

	Mix_Music *music = Mix_LoadMUS("Music/Washing.mp3");
	if (!music) {
		printf("Failed to load music! Error: %s\n", Mix_GetError());
		return 1;
	}

	Mix_PlayMusic(music, -1); // -1 means loop forever

	printf("Playing music... Press Enter to quit.\n");
	getchar();

	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_Quit();
}

// Main funtion
int main(int argc, char* argv[]) {

	short int argpos= 1;

	// If an argument's given run this
	if (argc == 2 ) {

		// The program expects an argument in the form <00:00:00>, which is 8 chars
		kickstart(argv[argpos]);
		// Music start
		playback();
	}
	// If not arguments run this bit
	else {
		printf("Please give argument in format <00:00:00>\n");
	}
	// You dont really need to specify a return value for the main func but i did anyway
	return 0;
}


