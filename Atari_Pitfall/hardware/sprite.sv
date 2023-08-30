module sprite(input [7:0] addr, output [7:0] data);

    parameter ADDR_WIDTH = 11;
    parameter DATA_WIDTH =  8;
	logic [ADDR_WIDTH-1:0] addr_reg;
				
	// ROM definition				
	parameter [0:2**ADDR_WIDTH-1][DATA_WIDTH-1:0] ROM = {
        8'b00000000, // 0
        8'b00000000, // 1
        8'b00000000, // 2
        8'b00000000, // 3
        8'b00000000, // 4
        8'b00000000, // 5
        8'b00000000, // 6
        8'b00000000, // 7
        8'b00000000, // 8
        8'b00000000, // 9
        8'b00000000, // a
        8'b00000000, // b
        8'b00000000, // c
        8'b00000000, // d
        8'b00000000, // e
        8'b00000000, // f
         // code x01
        8'b00000000, // 0
        8'b00000000, // 1
        8'b01111110, // 2  ******
        8'b10000001, // 3 *      *
        8'b10100101, // 4 * *  * *
        8'b10000001, // 5 *      *
        8'b10000001, // 6 *      *
        8'b10111101, // 7 * **** *
        8'b10011001, // 8 *  **  *
        8'b10000001, // 9 *      *
        8'b10000001, // a *      *
        8'b01111110, // b  ******
        8'b00000000, // c
        8'b00000000, // d
        8'b00000000, // e
        8'b00000000, // f
    };

assign data = ROM[addr];

endmodule