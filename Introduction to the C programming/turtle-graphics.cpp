#include <stdio.h>

#define FLOOR_DIM 50
#define INIT_XPOS 25		
#define INIT_YPOS 25		
#define PI 3.14159265358979323846264338327

int Floor[FLOOR_DIM][FLOOR_DIM] = { {0} };

int xpos = INIT_XPOS;
int ypos = INIT_YPOS;
enum Pen { DOWN, UP };

void walk(const int dir, const int pen);
void print_matrix(void);
int get_input(void);
int normalize_dir(int dir);

int main() {

    int input;
    int pen = DOWN;
    int dir = 0;		 
	printf("  Asagida numara ile belirtilmis olan yonergelerden\n istediginizi yanindaki numarayi enter ile girerek seklinizi cizdirebilirsiniz....\n\n");			   
    while (1) {
		input = get_input();
		switch (input) {
		case 1:
		    pen = DOWN;
		    break;
		case 2:
		    pen = UP;
		    break;	
		case 3:
		    dir -= 90;
		    dir = normalize_dir(dir);
		    printf("Kaplumbaganin yonu: %d\n", dir);
		    break;
		case 4:
		    dir += 90;
		    dir = normalize_dir(dir);
		    printf("Kaplumbaganin yonu: %d\n", dir);
		    break;
		case 5:
		    walk(dir, pen);
		    break;
		case 6:
			print_matrix();
			break;
		case 9:
	    	print_matrix();
	    	return 0;
		default:
	    	printf("Yanlis komut tekrar deneyin...\n");
		}			
    }				
}

int normalize_dir(int dir) {
    int res;

    if (dir < 0)
		res = 360 + dir;
    else if (dir >= 360)
		res = dir - 360;
    else
		res = dir;

    return res;

}

void walk(const int dir, const int pen) {

    int step;
    int i;
    int xposmodifier;
    int yposmodifier;

    if (dir == 0) {
		xposmodifier = 1;
		yposmodifier = 0;
    }
	else if (dir == 90) {
		xposmodifier = 0;
		yposmodifier = -1;	/* -1 because we're going up in the matrix */
    }
	else if (dir == 180) {
		xposmodifier = -1;
		yposmodifier = 0;
    }
	else if (dir == 270) {
		xposmodifier = 0;
		yposmodifier = 1;	/* 1 because we're going down in the matrix */
    }

    printf("Kac adim atmali? ");
    scanf("%d", &step);

    for (i = 0; i < step; i++) {
		xpos += xposmodifier;
		if (xpos < 0) {
	    	xpos = 0;
		}
		else if (xpos > FLOOR_DIM) {
	    	xpos = FLOOR_DIM;
		}

		ypos += yposmodifier;
		if (ypos < 0) {
	    	ypos = 0;
		}	
		else if (ypos > FLOOR_DIM) {
	    	ypos = FLOOR_DIM;
		}

		if (pen == UP) {
	    	Floor[ypos][xpos] = 1;
		}
    }
}

int get_input(void) {
    int input;
    printf("\n"
	   "1) Kalem yukariya\n"
	   "2) Kalem asagiya\n"
	   "3) Saga dondur\n"
	   "4) Sola dondur\n"
	   "5) Verilen deger kadar adim attir\n"
	   "6) Sekli yazdir\n" "9) Son.....\n\n" "Komutunuzu giriniz: ");
    scanf("%d", &input);
    return input;
}

void print_matrix(void)
{
    int i, j;

    for (i = 0; i < FLOOR_DIM; i++) {
		for (j = 0; j < FLOOR_DIM; j++)
	    	printf(Floor[i][j] ? "*" : ".");
		printf("\n");
    }
    printf("\n");
}
