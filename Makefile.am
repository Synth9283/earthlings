AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = earthlings
earthlings_SOURCES = \
    main.c src/events.c src/fps.c src/hitCheck.c src/mainMenu.c src/meteors.c src/process.c src/render.c src/scanKey.c src/startGame.c src/stopGame.c \
    libs/events.h libs/fps.h/ libs/hitCheck.h libs/mainMenu.h libs/meteors.h libs/objects.h libs/process.h libs/render.h libs/scanKey.h libs/startGame.h libs/stopGame.h

earthlings_CPPFLAGS = @SDL2_CFLAGS@ @SDL2_MIXER_CFLAGS@ @SDL2_TTF_CFLAGS@ @SDL2_IMAGE_CFLAGS@
earthlings_LDFLAGS = @SDL2_LIBS@ @SDL2_MIXER_LIBS@ @SDL2_TTF_LIBS@ @SDL2_IMAGE_LIBS@ -lm
