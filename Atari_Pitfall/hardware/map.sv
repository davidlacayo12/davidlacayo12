/*This is the module that randomly generates the next level in the map. 255 total levels available from 8 bits*/

module map(input logic Clk, Reset, dir, input logic[7:0] seed, output logic[7:0] map);

    logic r7, r5, r4, r3, r0, R0, R7;

    always_ff @ (posedge Clk)
        begin 
            if(Reset)
                map <= 8'b0;
            else
					if(new_level)
						begin
							if(dir) //if direction is 1, we are moving right, otherwise we will be moving left
								begin   //left shift
									map[7:1] <= seed[6:0];
									map[0] <= R0; 
								end
							 else    
								  begin   //right shift
										map[6:0] <= seed[7:1]
										map[7] <= R7;
								  end
						end
					else
						begin
							map <= seed;
						end
        end

    always_comb 
        begin
            r7 = seed[7];   //store old values from input register "seed" to use for combinational logic to calculate next level 
            r5 = seed[5];
            r4 = seed[4];
            r3 = seed[3];
            r0 = seed[0];

            //calculate logic based on direction. If 1, we are moving in the normal direction, and we need to find logic for LSB. Otherwise, we need logic for MSB
            if(dir)
                R0 = r3 ^ r4 ^ r5 ^ r7;
            else
                R7 = r4 ^ r5 ^ r6 ^ r0;       
        end

endmodule
