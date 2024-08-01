#include <stdio.h>

struct pos {
	int x;
	int y;
};

struct pos player_pos;

int maze[][8] = {
                {1,1,0,0,0,1,1,1},
                {1,1,1,1,0,0,0,0},
                {0,0,0,0,0,1,1,1},
                {1,0,1,1,0,0,1,1},
                {1,0,1,1,1,0,0,3},
                {1,0,0,0,1,0,1,1},
                {1,0,1,0,1,0,1,1},
                {0,0,1,0,1,0,1,1}
                };

int main(){

	void print_maze();
	int move(int mov);
	void refresh_player_pos();

	player_pos.y = 7;
	player_pos.x = 0;

	refresh_player_pos();
	while(1){
		printf("\033[H\033[J"); //clean the terminal
		printf("player pos, x = %d, y = %d", player_pos.x, player_pos.y);
		print_maze();
	
		printf("\nMovements: 1 - up; 2- right; 3 - down; 4-left");
		printf("\nmove: ");
		int m;
		scanf("%d", &m);
		
		move(m);
		refresh_player_pos();
	}

}

void print_maze(){
	printf("\n");
	for(int i =0; i < 8; ++ i){
		for(int j = 0; j < 8; ++j){
			if(maze[i][j] == 0){
				printf(" ");
			}else if(maze[i][j] == 2) {
				printf("*");
			}else if(maze[i][j] == 3) {
				printf("&");
			}else printf("#");

			printf(" ");

		}
		printf("\n");
	}
}

void refresh_player_pos(){
    for(int i =0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if( maze[i][j] == 2){
                maze[i][j] = 0;
            }
        }
    }

    maze[player_pos.y][player_pos.x] = 2;
}

int move(int mov){
	/*
		1 up
		2 right
		3 down
		4 left
	*/
	if ( mov == 1){
        int new_y = player_pos.y - 1;
		if(new_y < 0 || maze[ new_y][player_pos.x] == 1){
			return 0;
		}

		player_pos.y = new_y;
	}else if(mov == 2){
		int new_x = player_pos.x + 1;
        if(new_x > 7 || maze[ player_pos.y][new_x] == 1){
            return 0;
        }

        player_pos.x = new_x;

        return 1;
	}else if (mov  == 3) {
		int new_y = player_pos.y + 1;
		if(new_y > 7 || maze[new_y][player_pos.x] == 1){
			return 0;
		}

		player_pos.y = new_y;

		return 1;
	}else if( mov == 4){
        int new_x = player_pos.x - 1;
        if(new_x < 0 || maze[ player_pos.y][new_x] == 1){
            return 0;
        }

        player_pos.x = new_x;

        return 1;
	}
}
