module frame_mapper(input logic [9:0] HarryX, HarryY, DrawX, DrawY, Harry_Size, input logic Clk, toggle, Reset, blank, new_level, 
							input logic[7:0] keycode, seed,
								output run, harry_death, output[5:0] value);
							
logic[7:0] level;							
//Rolling Log Positions & Toggle
logic r_log1 = 1'b0;
logic r_log2 = 1'b0;
logic r_log3 = 1'b0;
logic[9:0] r_log1_X = 450; 
logic[9:0] r_log1_X_init = 450; 
logic[9:0] r_log1_Y = 280; 
logic[9:0] r_log1_Y_init = 280; 
logic[9:0] r_log2_X = 500; 
logic[9:0] r_log2_X_init = 500; 
logic[9:0] r_log2_Y = 280; 
logic[9:0] r_log2_Y_init = 280; 
logic[9:0] r_log3_X = 550; 
logic[9:0] r_log3_X_init = 550; 
logic[9:0] r_log3_Y = 280; 
logic[9:0] r_log3_Y_init = 280; 

//Stationary Log Positions and Toggle

logic s_log1 = 1'b0;
logic s_log2 = 1'b0;
logic s_log3 = 1'b0;
logic[9:0] s_log1_X = 50; 
logic[9:0] s_log1_Y = 280; 
logic[9:0] s_log2_X = 500; 
logic[9:0] s_log2_Y = 280; 
logic[9:0] s_log3_X = 550; 
logic[9:0] s_log3_Y = 280; 

logic[3:0] log_size_X = 16;
logic[4:0] log_size_Y = 24;

//Enemy Positions and Toggle

logic fire_en = 1'b0;
logic snake_en = 1'b0;
logic[9:0] fire_X = 475; 
logic[9:0] fire_Y = 280; 
logic[9:0] snake_X = 475; 
logic[9:0] snake_Y = 280;

logic[9:0] fire_size_X = 16;
logic[9:0] fire_size_Y = 24;
logic[9:0] snake_size_X = 16;
logic[9:0] snake_size_Y = 24; 

//Environment Positions and Toggle

logic hole1_en = 1'b0;
logic[9:0] hole1_X = 150; 
logic[9:0] hole1_Y = 275; 
logic hole2_en = 1'b0;
logic[9:0] hole2_X = 275; 
logic[9:0] hole2_Y = 275; 
logic hole3_en = 1'b0;
logic[9:0] hole3_X = 400; 
logic[9:0] hole3_Y = 275; 

logic[9:0] hole_size_X = 40;
logic[9:0] hole_size_Y = 70;

logic croc1_en = 1'b0;
logic[9:0] croc1_X = 200; 
logic[9:0] croc1_Y = 240; 
logic croc2_en = 1'b0;
logic[9:0] croc2_X = 275; 
logic[9:0] croc2_Y = 240; 
logic croc3_en = 1'b0;
logic[9:0] croc3_X = 350; 
logic[9:0] croc3_Y = 240; 

logic tar_pit_en = 1'b0;
logic[9:0] tar_pit_X = 300; 
logic[9:0] tar_pit_Y = 240; 

logic quicksand_en = 1'b0;
logic[9:0] quicksand_X = 300; 
logic[9:0] quicksand_Y = 240; 

logic wall_left = 1'b0;
logic[9:0] wall_left_X = 75; 
logic[9:0] wall_left_Y = 345; 

logic wall_right = 1'b0;
logic[9:0] wall_right_X = 550; 
logic[9:0] wall_right_Y = 345; 

logic[5:0] wall_size_X = 40;
logic[6:0] wall_size_Y = 120;

logic scorpion_en = 1'b0;	//If there are no walls (i.e. level[3:5] == 010 | 011) we will have a scorpion on the bottom
logic[9:0] scorpion_X = 200; 
logic[9:0] scorpion_Y = 465; 

logic vine_en = 1'b0;
logic[1:0] tree = 2'b00;
//Different types of collisions that will be set and will determine the impact of our lives and score 


logic life_collision = 1'b0;	//this is basically for every collision that will cost the player a life
logic log_collision = 1'b0;	//this for log collisions, which will only cost the player points and not lives 
logic treasure_collision = 1'b0;
logic treasure_en = 1'b0;
logic[1:0] treasure = 2'b00;	//4 different types of treasure: money bag = 00, silver bar = 01, gold bar = 10, diamond ring = 11
logic hole_collision = 1'b0;	//if 1, animation of falling into bottom layer
logic ladder_collision = 1'b0; //if 1, animation of climbing up/down ladder based on player input 
logic vine_collision = 1'b0;

always_comb
	begin:Treasure_enable
		if(level[5:3] == 3'b101)	//This tells us if there is a treasure or not 
			begin 
				treasure_en = 1'b1;
			end
		else
			treasure_en = 1'b0;
	
	end

//Logic to figure out what obstacles and treasures there will be on the current level based on our 8-bit current level seed
//always_comb
//	begin
//		if(treasure_en)
//			begin
//				case(level[2:0])
//						3'b000: treasure = 2'b00;					
//						3'b001: treasure = 2'b01;						
//						3'b010: treasure = 2'b10;
//						3'b011: treasure = 2'b11;
//						3'b100: treasure = 2'b00;	
//						3'b101: treasure = 2'b01;
//						3'b110: treasure = 2'b10;
//						3'b111: treasure = 2'b11;
//						default: ;
//					endcase
//					
//					tar_pit_en = 1'b1;
//					r_log1 = 1'b0;
//					r_log2 = 1'b0;
//					r_log3 = 1'b0;
//					s_log1 = 1'b0;
//					s_log2 = 1'b0;
//					fire_en = 1'b0;
//					snake_en = 1'b0;
//			end
//		
//		else
//			begin	//No treasure, so normal obstacles
//			tar_pit_en = 1'b0;
//			treasure = 2'b00;
//				case(level[2:0])
//					3'b000: r_log1 = 1'b1;
//					
//					3'b001: 
//						begin
//							r_log1 = 1'b1;
//							r_log2 = 1'b1;
//						end
//						
//					3'b010: 
//						begin
//							r_log1 = 1'b1;
//							r_log2 = 1'b1;
//						end
//						
//					3'b011: 
//						begin
//							r_log1 = 1'b1;
//							r_log2 = 1'b1;
//							r_log3 = 1'b1;
//						end
//					3'b100: 
//						begin
//							s_log1 = 1'b1;
//						end	
//					3'b101: 
//						begin
//							s_log1 = 1'b1;
//							s_log2 = 1'b1;
//							s_log3 = 1'b1;
//						end
//					
//					3'b110:	fire_en = 1'b1;
//					
//					3'b111: 	snake_en = 1'b1;
//						
//					default: 
//						begin
//							fire_en = 1'b0;
//							snake_en = 1'b0;
//							r_log1 = 1'b0;
//							r_log2 = 1'b0;
//							r_log3 = 1'b0;
//							s_log1 = 1'b0;
//							s_log2 = 1'b0;
//							s_log3 = 1'b0;
//						end
//				endcase
//			end
//	end
//	

//	always_comb
//		begin 
//			case(level[5:3])
//				3'b000: hole1_en = 1'b1;					
//				3'b001: 
//					begin
//						hole1_en = 1'b1;
//						hole2_en = 1'b1;
//						hole3_en = 1'b1;
//					end
//				3'b010:	scorpion_en = 1'b1;
//				3'b011:	scorpion_en = 1'b1;
//				3'b100: 
//					begin
//						croc1_en = 1'b1;
//						croc2_en = 1'b1;
//						croc3_en = 1'b1;
//					end	
//				3'b101: 
//					begin
//						tar_pit_en = 1'b1;
//						vine_en = 1'b1;
//					end 
//				3'b110: tar_pit_en = 1'b1;
//				3'b111: quicksand_en = 1'b1;
//				default: ;
//			endcase
//		end
//		
//	always_comb
//		begin
//			if(level[7])
//				begin
//					wall_right = 1'b0;
//					wall_left = 1'b1;
//				end
//			else
//				begin
//					wall_left = 1'b0;
//					wall_right = 1'b1;
//				end	
//		end
//			

	logic [7:0] current_level, map;	//level stored in register that will be changed with logic to generate 255 levels
	assign current_level = 8'b00000000;
	
	logic harry_en = 1'b1;		
	logic[3:0] harry_state = 4'b0000;		
	logic[0:31][0:15][0:5] harry_animation;
	logic[9:0] harry_size_X, harry_size_Y;
	assign harry_size_X = 16;
	assign harry_size_Y = 32;
	

	//This block controls our harry animation, changes the run state every second
	logic [18:0] harry_movement_counter = 19'b0;
	always_ff @ (posedge Clk)
		begin: Harry_animation
			if(harry_movement_counter == 19'b1111010000100100000)	//every second, change the animation
				begin
					if(keycode == 8'h04 || keycode == 8'h07)
						begin:Run_animation
							if(harry_state == 4'b0101)	//run state 4
								harry_state <= 4'b0010;	//reset to run state 1
							else
								harry_state <= harry_state + 4'b0001;
						end
					else if(keycode == 8'h2C)
						begin
							harry_state <= 4'b0001;
						end
					harry_movement_counter <= 19'b0;
				end
			else
				harry_movement_counter <= harry_movement_counter + 1'b1;
		end
	
	
	logic[0:23][0:15][0:5] log1, log2, fire, snake; 
	logic[0:69][0:39][0:5] hole;
	logic[0:119][0:39][0:5] wall;
	
	harry_sprite hs0(.Clk(Clk), .harry_state(harry_state), .harry_animation(harry_animation) );	
	sprite_table st0( .Clk(Clk), .log1(log1), .log2(log2), .fire(fire), .snake(snake), .wall(wall) );
	//map m0(	.Clk(Clk), .Reset(Reset), .new_level(new_level), .seed(seed), .map(map) );
	//log l0( .Reset(Reset), .frame_clk(Clk), .Ball_X_init(r_log1_X_init), .Ball_Y_init(r_log1_Y_init), .BallX(r_log1_X), .BallY(r_log1_Y), .BallS_X(), .BallS_Y() );
	//log l1(.Reset(Reset), .frame_clk(Clk), .Ball_X_init(r_log2_X_init), .Ball_Y_init(r_log2_Y_init), .BallX(r_log2_X), .BallY(r_log2_Y), .BallS_X(), .BallS_Y() );
	//log l2( .Reset(Reset), .frame_clk(Clk), .Ball_X_init(r_log3_X_init), .Ball_Y_init(r_log3_Y_init), .BallX(r_log3_X), .BallY(r_log3_Y), .BallS_X(), .BallS_Y() );
	//pit p0( );
	
	always_comb
		begin: Test_logic
			wall_left = 1'b0;
			wall_right = 1'b1;
			s_log1 = 1'b1;
			s_log2 = 1'b0;
			s_log3 = 1'b0;	
			r_log1 = 1'b0;
			r_log2 = 1'b0;
			r_log3 = 1'b0;
			hole1_en = 1'b1;
			hole2_en = 1'b1;
			hole3_en = 1'b1;
			fire_en = 1'b0;
			snake_en = 1'b1;
		end

//	always_comb
//		begin: Collision_logic
//			if(harry_en && (DrawX >= HarryX) && (DrawX < HarryX + harry_size_X) && (DrawY >= HarryY) && (DrawY < HarryY + harry_size_Y) && (harry_animation[DrawY - HarryY][DrawX - HarryX] != 6'b000000) )
//				begin
//					if(hole1_en && (DrawX >= hole1_X) && (DrawX < hole1_X + hole_size_X) && (DrawY >= hole1_Y) && (DrawY < hole1_Y + hole_size_Y) )
//						begin: hole_collision
//							harry_death = 1'b1;
//						end
//					else if((wall_left && (DrawX >= wall_left_X) && (DrawX < wall_left_X + wall_size_X) && (DrawY >= wall_left_Y) && (DrawY < wall_left_Y + wall_size_Y)) || 
//						(wall_right && (DrawX >= wall_right_X) && (DrawX < wall_right_X + wall_size_X) && (DrawY >= wall_right_Y) && (DrawY < wall_right_Y + wall_size_Y))	)
//						begin:	Wall_collision
//							harry_death = 1'b1;
//						end
//					else if((s_log1 && (DrawX >= s_log1_X) && (DrawX < s_log1_X + log_size_X) && (DrawY >= s_log1_Y) && (DrawY < s_log1_Y + log_size_Y) && (log1[DrawY - s_log1_Y][DrawX - s_log1_X] != 6'b000000) ) || 
//						(s_log2 && (DrawX >= s_log2_X) && (DrawX < s_log2_X + log_size_X) && (DrawY >= s_log2_Y) && (DrawY < s_log2_Y + log_size_Y) && (log1[DrawY - s_log2_Y][DrawX - s_log2_X] != 6'b000000) ) || 
//						(s_log3 && (DrawX >= s_log3_X) && (DrawX < s_log3_X + log_size_X) && (DrawY >= s_log3_Y) && (DrawY < s_log3_Y + log_size_Y) && (log1[DrawY - s_log3_Y][DrawX - s_log3_X] != 6'b000000)) )
//						begin: stationary_log_collision
//							harry_death = 1'b1;
//						end
//					else if((r_log1 && (DrawX >= r_log1_X) && (DrawX < r_log1_X + log_size_X) && (DrawY >= r_log1_Y) && (DrawY < r_log1_Y + log_size_Y) && (log1[DrawY - r_log1_Y][DrawX - r_log1_X] != 6'b000000)) || 
//							(r_log2 && (DrawX >= r_log2_X) && (DrawX < r_log2_X + log_size_X) && (DrawY >= r_log2_Y) && (DrawY < r_log2_Y + log_size_Y) && (log1[DrawY - r_log2_Y][DrawX - r_log2_X] != 6'b000000)) ||
//							(r_log3 && (DrawX >= r_log3_X) && (DrawX < r_log3_X + log_size_X) && (DrawY >= r_log3_Y) && (DrawY < r_log3_Y + log_size_Y) && (log1[DrawY - r_log3_Y][DrawX - r_log3_X] != 6'b000000)) )
//						begin: rolling_log_collision
//							harry_death =1'b1;
//						end
//					else if((hole1_en && (DrawX >= hole1_X) && (DrawX < hole1_X + hole_size_X) && (DrawY >= hole1_Y) && (DrawY < hole1_Y + hole_size_Y)) || 
//					(hole2_en && (DrawX >= hole2_X) && (DrawX < hole2_X + hole_size_X) && (DrawY >= hole2_Y) && (DrawY < hole2_Y + hole_size_Y)) ||
//					(hole3_en && (DrawX >= hole3_X) && (DrawX < hole3_X + hole_size_X) && (DrawY >= hole3_Y) && (DrawY < hole3_Y + hole_size_Y)) )
//						begin
//							harry_death = 1'b1;
//						end
//					else if(fire_en && (DrawX >= fire_X) && (DrawX < fire_X + fire_size_X) && (DrawY >= fire_Y) && (DrawY < fire_Y + fire_size_Y) && (fire[DrawY - fire_Y][DrawX - fire_X] != 6'b000000) )
//						begin
//							harry_death = 1'b1;
//						end
//					else if(snake_en && (DrawX >= snake_X) && (DrawX < snake_X + snake_size_X) && (DrawY >= snake_Y) && (DrawY < snake_Y + snake_size_Y) && (snake[DrawY - snake_Y][DrawX - snake_X] != 6'b000000) )
//						begin
//							harry_death = 1'b1;
//						end
//					else
//						begin
//							harry_death = 1'b0;
//						end
//				end
//			else
//				begin
//					harry_death = 1'b0;
//				end	
//		end

//	always_comb
//		begin: collision_logic
//			if(harry_en)
//				begin
//					if()
//						begin
//						
//						end
//				end
//			else
//				harry_death = 1'b0;
//		end

		
	always_comb
		begin: Color_logic
			if(blank)
				begin	//Draw Harry
					if(harry_en && (DrawX >= HarryX) && (DrawX < HarryX + harry_size_X) && (DrawY >= HarryY) && (DrawY < HarryY + harry_size_Y) && (harry_animation[DrawY - HarryY][DrawX - HarryX] != 6'b000000) )
					begin:Draw_Harry
						value = harry_animation[DrawY - HarryY][DrawX - HarryX];
					end
					
					//Draw Underground Wall
					else if(wall_left && (DrawX >= wall_left_X) && (DrawX < wall_left_X + wall_size_X) && (DrawY >= wall_left_Y) && (DrawY < wall_left_Y + wall_size_Y) )
						begin:Wall_left
							value = wall[DrawY - wall_left_Y][DrawX - wall_left_X];
						end
					else if(wall_right && (DrawX >= wall_right_X) && (DrawX < wall_right_X + wall_size_X) && (DrawY >= wall_right_Y) && (DrawY < wall_right_Y + wall_size_Y))
						begin:Wall_right
							value = wall[DrawY - wall_right_Y][DrawX - wall_right_X];
						end
					
					//Draw Stationary Logs	
					else if(s_log1 && (DrawX >= s_log1_X) && (DrawX < s_log1_X + log_size_X) && (DrawY >= s_log1_Y) && (DrawY < s_log1_Y + log_size_Y) && (log1[DrawY - s_log1_Y][DrawX - s_log1_X] != 6'b000000))
						begin: Stationary_log_1
							value = log1[DrawY - s_log1_Y][DrawX - s_log1_X];
						end
					else if(s_log2 && (DrawX >= s_log2_X) && (DrawX < s_log2_X + log_size_X) && (DrawY >= s_log2_Y) && (DrawY < s_log2_Y + log_size_Y) && (log1[DrawY - s_log2_Y][DrawX - s_log2_X] != 6'b000000))
						begin: Stationary_log_2
							value = log1[DrawY - s_log2_Y][DrawX - s_log2_X];
						end
					else if(s_log3 && (DrawX >= s_log3_X) && (DrawX < s_log3_X + log_size_X) && (DrawY >= s_log3_Y) && (DrawY < s_log3_Y + log_size_Y) && (log1[DrawY - s_log3_Y][DrawX - s_log3_X] != 6'b000000))
						begin: Stationary_log_3
							value = log1[DrawY - s_log3_Y][DrawX - s_log3_X];
						end
					
					//Draw Rolling Logs
					else if(r_log1 && (DrawX >= r_log1_X) && (DrawX < r_log1_X + log_size_X) && (DrawY >= r_log1_Y) && (DrawY < r_log1_Y + log_size_Y) && (log1[DrawY - r_log1_Y][DrawX - r_log1_X] != 6'b000000))
						begin: Rolling_log_1
							value = log1[DrawY - r_log1_Y][DrawX - r_log1_X];
						end
					else if(r_log2 && (DrawX >= r_log2_X) && (DrawX < r_log2_X + log_size_X) && (DrawY >= r_log2_Y) && (DrawY < r_log2_Y + log_size_Y) && (log1[DrawY - r_log2_Y][DrawX - r_log2_X] != 6'b000000))
						begin: Rolling_log_2
							value = log1[DrawY - r_log2_Y][DrawX - r_log2_X];
						end
					else if(r_log3 && (DrawX >= r_log3_X) && (DrawX < r_log3_X + log_size_X) && (DrawY >= r_log3_Y) && (DrawY < r_log3_Y + log_size_Y) && (log1[DrawY - r_log3_Y][DrawX - r_log3_X] != 6'b000000))
						begin: Rolling_log_3
							value = log1[DrawY - r_log3_Y][DrawX - r_log3_X];
						end
					
					//Draw Holes
					else if(hole1_en && (DrawX >= hole1_X) && (DrawX < hole1_X + hole_size_X) && (DrawY >= hole1_Y) && (DrawY < hole1_Y + hole_size_Y) && ((DrawY >= 285 && DrawY < 300) || DrawY > 310) )
						begin
							value = hole[DrawY - hole1_Y][DrawX - hole1_X];
						end
					else if(hole2_en && (DrawX >= hole2_X) && (DrawX < hole2_X + hole_size_X) && (DrawY >= hole2_Y) && (DrawY < hole2_Y + hole_size_Y) && ((DrawY >= 285 && DrawY < 300) || DrawY > 310) )
						begin
							value = hole[DrawY - hole2_Y][DrawX - hole2_X];
						end
					else if(hole3_en && (DrawX >= hole3_X) && (DrawX < hole3_X + hole_size_X) && (DrawY >= hole3_Y) && (DrawY < hole3_Y + hole_size_Y) && ((DrawY >= 285 && DrawY < 300) || DrawY > 310) )
						begin
							value = hole[DrawY - hole3_Y][DrawX - hole3_X];
						end
					
					//Draw Fire and Snake
					else if(fire_en && (DrawX >= fire_X) && (DrawX < fire_X + fire_size_X) && (DrawY >= fire_Y) && (DrawY < fire_Y + fire_size_Y) && (fire[DrawY - fire_Y][DrawX - fire_X] != 6'b000000) )
						begin
							value = fire[DrawY - fire_Y][DrawX - fire_X];
						end
					else if(snake_en && (DrawX >= snake_X) && (DrawX < snake_X + snake_size_X) && (DrawY >= snake_Y) && (DrawY < snake_Y + snake_size_Y) && (snake[DrawY - snake_Y][DrawX - snake_X] != 6'b000000) )
						begin
							value = snake[DrawY - snake_Y][DrawX - snake_X]; 
						end
						
					else	//otherwise draw the background and floor based on where we are on screen -->no collision
						begin
							if(DrawY >= 0 && DrawY < 100)
								value = 15;	
							else if(DrawY >= 100 && DrawY < 275)
								value = 31;	//background[DrawX][DrawY-100];
							else if(DrawY >= 275 && DrawY < 310)
								value = 	40;	//floor[DrawX][DrawY - 316];
							else if(DrawY >=310 && DrawY < 345)
								value = 39;
							else if(DrawY >= 465 && DrawY < 480)
								value = 39;
							else
								value = 6'b0;	
						end
				end
			else
				value = 6'b0;
		end
		
		
		
	assign current_level = map;	//send the current map into our seed to be changed if we go off screen right or left	

endmodule 