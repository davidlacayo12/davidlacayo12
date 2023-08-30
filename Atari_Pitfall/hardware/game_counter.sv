/*This module contains counters for treasures, total score, level, and time counter*/

module score(input logic Clk, Reset, ADD_SUB, input logic[12:0] score_change, output logic [16:0] score_count);

    always_ff @ (posedge Clk)
        begin
            if(Reset)
                score_count <= 17'b0;   //17 bits gives us 131k numbers, but we will only need 114,000 since it is our max score for pitfall
            else    
                begin
                    if(ADD_SUB == 1) //if 1, we are subtracting, otherwise we are adding the score change
                        score_count <= score_count - score_change;
                    else 
                        score_count <= score_count + score_change;
                end
        end
        

endmodule

module timer(input logic Clk, Reset, Run, input logic [10:0] Din, output logic [10:0] Dout, output logic game_end); //MAKE SURE CLOCK IS THE SECOND COUNTER
    logic [18:0] sec;
    //assign Din = 11'b10010110000;
    assign sec = 19'b0;
    assign game_end = 1'b0;
    always_ff @ (posedge Clk)
        begin
            if(Reset)   //If we hit reset or run out of time, reset the clock 
                Dout <= 11'b10010110000;    //resets clock to 1200 seconds, or 20 minutes
            else if(Din == 11'b0)   //if our timer hits 0, end the game 
                game_end <= 1'b1;
            else   
                begin
                    if(Run && sec == 19'b1111010000100100000) //if we are playing the game, and one second has gone past, decrease the time 
                        Dout <= Din - 1'b1; //take one second off of our counter if we are playing the game
                    else
                        Dout <= Din;
                end
         end    
    
    always_comb
        begin
            if(sec == 19'b1111010000100100000)  //if our counter hits 500,000 -- one second has gone past, and we need to reset our counter: otherwise increment 
                sec = 19'b0;
            else
                sec = sec + 1'b1;
        end
           

       
endmodule

module level_counter(input logic Clk, Reset, next_level, input logic [7:0] Din, output logic [7:0] level_counter, output logic end_game);

    always_ff @ (posedge Clk)
        if(Reset)
            level_counter <= 7'b0;
        else
            if(next_level) //if we have moved to our next level, increase our level counter
                level_counter <= Din + 1'b1;
            else    
                level_counter <= Din;

    always_comb
        begin 
            if(Din == 8'b11111111)  //if we have reached level 255, then we end the game 
                end_game = 1'b1;
            else
                end_game = 1'b0;
        end

endmodule

module treasure_counter(input logic Clk, Reset, treasure_found, input logic [4:0] Din, output logic [4:0] treasure_counter, output logic end_game);

    always_ff @ (posedge Clk)
        begin 
            if(Reset)
                treasure_counter <= 5'b0;
            else 
                if(treasure_found)  //if we have found a treasure, increase our treasure count
                    treasure_counter <= Din + 1'b1;
                else
                    treasure_counter <= Din;
        end
    
    always_comb 
        begin   //if we have found all 32 treasures, end the game 
            if(Din == 5'b11111)
                end_game = 1'b1;
            else 
                end_game = 1'b0;
        end 

endmodule