// 64 Colors --> same as the NTSC color palette
//This module gets its input value from frame_decider
// Based on value it outputs the color from the pallete

module  pitfall_color_mapper (input [5:0] value,
                       output logic [7:0]  Red, Green, Blue );

always_comb
	begin:RGB_Display
		if((value==6'b000000))
			begin
			Red=8'h00;
			Green=8'h00;
			Blue=8'h00;
			end
		else if ((value==6'b000001))
			begin
			Red=8'h00;
			Green=8'h00;
			Blue=8'h55;
			end
		else if ((value==6'b000010))
			begin
			Red=8'h00;
			Green=8'h00;
			Blue=8'haa;
			end
		else if ((value==6'b000011))
			begin
			Red=8'h00;
			Green=8'h00;
			Blue=8'hff;
			end
		else if ((value==6'b000100))
			begin
			Red=8'h55;
			Green=8'h00;
			Blue=8'h00;
			end
		else if ((value==6'b000101))
			begin
			Red=8'h55;
			Green=8'h00;
			Blue=8'h55;
			end
		else if ((value==6'b000110))
			begin
			Red=8'h55;
			Green=8'h00;
			Blue=8'haa;
			end
		else if ((value==6'b000111))
			begin
			Red=8'h55;
			Green=8'h00;
			Blue=8'hff;
			end
		else if ((value==6'b001000))
			begin
			Red=8'haa;
			Green=8'h00;
			Blue=8'h00;
			end
		else if ((value==6'b001001))
			begin
			Red=8'haa;
			Green=8'h00;
			Blue=8'h55;
			end
		else if ((value==6'b001010))
			begin
			Red=8'haa;
			Green=8'h00;
			Blue=8'haa;
			end
		else if ((value==6'b001011))
			begin
			Red=8'haa;
			Green=8'h00;
			Blue=8'hff;
			end
		else if ((value==6'b001100))
			begin
			Red=8'hff;
			Green=8'h00;
			Blue=8'h55;
			end
		else if ((value==6'b001101))
			begin
			Red=8'hff;
			Green=8'h00;
			Blue=8'haa;
			end
		else if ((value==6'b001110))
			begin
			Red=8'hff;
			Green=8'h00;
			Blue=8'hff;
			end
		else if ((value==6'b001111))
			begin
			Red=8'h00;
			Green=8'h55;
			Blue=8'h00;
			end
		else if ((value==6'b010000))
			begin
			Red=8'h00;
			Green=8'h55;
			Blue=8'h55;
			end
		else if ((value==6'b010001))
			begin
			Red=8'h00;
			Green=8'h55;
			Blue=8'haa;
			end
		else if ((value==6'b010010))
			begin
			Red=8'h00;
			Green=8'h55;
			Blue=8'hff;
			end
		else if ((value==6'b010011))
			begin
			Red=8'h55;
			Green=8'h55;
			Blue=8'h00;
			end
		else if ((value==6'b010100))
			begin
			Red=8'h55;
			Green=8'h55;
			Blue=8'h55;
			end
		else if ((value==6'b010101))
			begin
			Red=8'h55;
			Green=8'h55;
			Blue=8'haa;
			end
		else if ((value==6'b010110))
			begin
			Red=8'h55;
			Green=8'h55;
			Blue=8'hff;
			end
		else if ((value==6'b010111))
			begin
			Red=8'haa;
			Green=8'h55;
			Blue=8'h00;
			end
		else if ((value==6'b011000))
			begin
			Red=8'haa;
			Green=8'h55;
			Blue=8'h55;
			end
		else if ((value==6'b011001))
			begin
			Red=8'haa;
			Green=8'h55;
			Blue=8'haa;
			end
		else if ((value==6'b011010))
			begin
			Red=8'haa;
			Green=8'h55;
			Blue=8'hff;
			end
		else if ((value==6'b011011))
			begin
			Red=8'hff;
			Green=8'h55;
			Blue=8'h00;
			end
		else if ((value==6'b011100))
			begin
			Red=8'hff;
			Green=8'h55;
			Blue=8'h55;
			end
		else if ((value==6'b011101))
			begin
			Red=8'hff;
			Green=8'h55;
			Blue=8'haa;
			end
		else if ((value==6'b011110))
			begin
			Red=8'hff;
			Green=8'h55;
			Blue=8'hff;
			end
		else if ((value==6'b011111))
			begin
			Red=8'h00;
			Green=8'haa;
			Blue=8'h00;
			end
		else if ((value==6'b100000))
			begin
			Red=8'h00;
			Green=8'haa;
			Blue=8'h55;
			end
		else if ((value==6'b100001))
			begin
			Red=8'h00;
			Green=8'haa;
			Blue=8'haa;
			end
		else if ((value==6'b100010))
			begin
			Red=8'h00;
			Green=8'haa;
			Blue=8'hff;
			end
		else if ((value==6'b100011))
			begin
			Red=8'h55;
			Green=8'haa;
			Blue=8'h00;
			end
		else if ((value==6'b100100))
			begin
			Red=8'h55;
			Green=8'haa;
			Blue=8'h55;
			end
		else if ((value==6'b100101))
			begin
			Red=8'h55;
			Green=8'haa;
			Blue=8'haa;
			end
		else if ((value==6'b100110))
			begin
			Red=8'h55;
			Green=8'haa;
			Blue=8'hff;
			end
		else if ((value==6'b100111))
			begin
			Red=8'haa;
			Green=8'haa;
			Blue=8'h00;
			end
		else if ((value==6'b101000))
			begin
			Red=8'haa;
			Green=8'haa;
			Blue=8'h55;
			end
		else if ((value==6'b101001))
			begin
			Red=8'haa;
			Green=8'haa;
			Blue=8'haa;
			end
		else if ((value==6'b101010))
			begin
			Red=8'haa;
			Green=8'haa;
			Blue=8'hff;
			end
		else if ((value==6'b101011))
			begin
			Red=8'hff;
			Green=8'haa;
			Blue=8'h00;
			end
		else if ((value==6'b101100))
			begin
			Red=8'hff;
			Green=8'haa;
			Blue=8'h55;
			end
		else if ((value==6'b101101))
			begin
			Red=8'hff;
			Green=8'haa;
			Blue=8'haa;
			end
		else if ((value==6'b101110))
			begin
			Red=8'hff;
			Green=8'haa;
			Blue=8'hff;
			end
		else if ((value==6'b101111))
			begin
			Red=8'h00;
			Green=8'hff;
			Blue=8'h00;
			end
		else if ((value==6'b110000))
			begin
			Red=8'h00;
			Green=8'hff;
			Blue=8'h55;
			end
		else if ((value==6'b110001))
			begin
			Red=8'h00;
			Green=8'hff;
			Blue=8'haa;
			end
		else if ((value==6'b110010))
			begin
			Red=8'h00;
			Green=8'hff;
			Blue=8'hff;
			end
		else if ((value==6'b110011))
			begin
			Red=8'h55;
			Green=8'hff;
			Blue=8'h00;
			end
		else if ((value==6'b110100))
			begin
			Red=8'h55;
			Green=8'hff;
			Blue=8'h55;
			end
		else if ((value==6'b110101))
			begin
			Red=8'h55;
			Green=8'hff;
			Blue=8'haa;
			end
		else if ((value==6'b110110))
			begin
			Red=8'h55;
			Green=8'hff;
			Blue=8'hff;
			end
		else if ((value==6'b110111))
			begin
			Red=8'haa;
			Green=8'hff;
			Blue=8'h00;
			end
		else if ((value==6'b111000))
			begin
			Red=8'haa;
			Green=8'hff;
			Blue=8'h55;
			end
		else if ((value==6'b111001))
			begin
			Red=8'haa;
			Green=8'hff;
			Blue=8'haa;
			end
		else if ((value==6'b111010))
			begin
			Red=8'haa;
			Green=8'hff;
			Blue=8'hff;
			end
		else if ((value==6'b111011))
			begin
			Red=8'hff;
			Green=8'hff;
			Blue=8'h00;
			end
		else if ((value==6'b111100))
			begin
			Red=8'hff;
			Green=8'hff;
			Blue=8'h55;
			end
		else if ((value==6'b111101))
			begin
			Red=8'hff;
			Green=8'hff;
			Blue=8'haa;
			end
		else if ((value==6'b111110))
			begin
			Red=8'hff;
			Green=8'hff;
			Blue=8'hff;
			end
		else
			begin
			Red=8'hff ;
			Green=8'hff;
			Blue=8'hff;
			end
	end
endmodule 