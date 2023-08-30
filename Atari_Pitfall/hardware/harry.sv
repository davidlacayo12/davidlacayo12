////Handles the movements for our character "Harry" based on the keycodes generated from the USB PIO 

//-------------------------------------------------------------------------
//    Ball.sv                                                            --
//    Viral Mehta                                                        --
//    Spring 2005                                                        --
//                                                                       --
//    Modified by Stephen Kempf 03-01-2006                               --
//                              03-12-2007                               --
//    Translated by Joe Meng    07-07-2013                               --
//    Fall 2014 Distribution                                             --
//                                                                       --
//    For use with ECE 298 Lab 7                                         --
//    UIUC ECE Department                                                --
//-------------------------------------------------------------------------


module  harry ( input Reset, frame_clk, harry_death,
					input [7:0] keycode,
               output [9:0]  HarryX, HarryY, HarryS_X, HarryS_Y, output logic new_level);
    
    logic [9:0] Ball_X_Pos, Ball_X_Motion, Ball_Y_Pos, Ball_Y_Motion, Ball_Size_Y, Ball_Size_X;
	 
    parameter [9:0] Ball_X_Center=20;  // Center position on the X axis
    parameter [9:0] Ball_Y_Center=280;  // Center position on the Y axis
    parameter [9:0] Ball_X_Min=0;       // Leftmost point on the X axis
    parameter [9:0] Ball_X_Max=639;     // Rightmost point on the X axis
    parameter [9:0] Ball_Y_Min=0;       // Topmost point on the Y axis
    parameter [9:0] Ball_Y_Max=479;     // Bottommost point on the Y axis
    parameter [9:0] Ball_X_Step=1;      // Step size on the X axis
    parameter [9:0] Ball_Y_Step=1;      // Step size on the Y axis
	 

    assign Ball_Size_Y = 32;  // assigns the value 4 as a 10-digit binary number, ie "0000000100"
	 assign Ball_Size_X = 16;
	 
	 logic jump_en = 1'b0;
//	 logic[] count = x'b0;
//	 logic jump_up = 1'b0;
//	 logic jump_down = 1'b0;
	
    always_ff @ (posedge Reset or posedge frame_clk )
    begin: Move_Ball
        if (Reset)  // Asynchronous Reset
        begin 
            Ball_Y_Motion <= 10'd0; //Ball_Y_Step;
				Ball_X_Motion <= 10'd0; //Ball_X_Step;
				Ball_Y_Pos <= Ball_Y_Center;
				Ball_X_Pos <= Ball_X_Center;
        end
		  
		  else if(new_level)
			begin
				Ball_Y_Pos <= Ball_Y_Center;
				Ball_X_Pos <= Ball_X_Center;
				new_level <= 1'b0;
			end
			
		  else if(harry_death)
			begin
				Ball_Y_Pos <= Ball_Y_Center;
				Ball_X_Pos <= Ball_X_Center;
			end
			
        else 
        begin 
				 if ( (Ball_Y_Pos + Ball_Size_Y) >= Ball_Y_Max )  // Ball is at the bottom edge, BOUNCE!
					  Ball_Y_Motion <= (~ (Ball_Y_Step) + 1'b1);  // 2's complement.
					  
				 else if ( (Ball_Y_Pos - Ball_Size_Y) <= Ball_Y_Min )  // Ball is at the top edge, BOUNCE!
					  Ball_Y_Motion <= Ball_Y_Step;
					  
				  else if ( (Ball_X_Pos + Ball_Size_X) >= Ball_X_Max )  // Ball is at the Right edge, GENERATE NEW LEVEL AND RESET POSITION
						begin
							new_level <= 1'b1;
						end
							
					  
				 else if ( (Ball_X_Pos - Ball_Size_X) <= Ball_X_Min )  // Ball is at the Left edge, BOUNCE!
					  Ball_X_Motion <= Ball_X_Step;
					  
				 else 
					  Ball_Y_Motion <= Ball_Y_Motion;  // Ball is somewhere in the middle, don't bounce, just keep moving
				 
				 case (keycode)
					8'h00 :
						begin
							Ball_Y_Motion <= 0;
							Ball_X_Motion <= 0;
						end
					8'h04 : begin

								Ball_X_Motion <= -1;//A
								Ball_Y_Motion<= 0;
							  end
					        
					8'h07 : begin
								
					        Ball_X_Motion <= 1;//D
							  Ball_Y_Motion <= 0;
							  end

							  
					8'h16 : begin

					        Ball_Y_Motion <= 1;//S
							  Ball_X_Motion <= 0;
							 end
							  
					8'h1A : begin
					        Ball_Y_Motion <= -1;//W
							  Ball_X_Motion <= 0;
							 end	
					8'h2C:  begin	//space bar
							jump_en <= 1'b1;
							end
					default: ;
			   endcase
				Ball_Y_Pos <= (Ball_Y_Pos + Ball_Y_Motion);  // Update ball position
				Ball_X_Pos <= (Ball_X_Pos + Ball_X_Motion);
		end  
    end
       
    assign HarryX = Ball_X_Pos;
   
    assign HarryY = Ball_Y_Pos;
   
    assign HarryS_Y = Ball_Size_Y;
	 
	 assign HarryS_X = Ball_Size_X;
    

endmodule 