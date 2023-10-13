module harry_sprite(input logic Clk, input logic[3:0] harry_state, output logic[0:31][0:15][0:5] harry_animation);

	//all harry sprites are 16x32
	logic[0:31][0:15][0:5] harry;
	logic[0:31][0:15][0:5] harry_jump;
	logic[0:31][0:15][0:5] harry_run1;
	logic[0:31][0:15][0:5] harry_run2;
	logic[0:31][0:15][0:5] harry_run3;
	logic[0:31][0:15][0:5] harry_run4;
	logic[0:31][0:15][0:5] harry_run5;
	logic[0:31][0:15][0:5] harry_vine;
	logic[0:31][0:15][0:5] harry_climb1;
	logic[0:31][0:15][0:5] harry_climb2;

	always_comb
	begin
	
	harry <=
	'{
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{23,23,23,23,23,23,0,0,0,0,0,0,0,0,0,0},
	'{28,28,28,28,28,28,0,0,0,0,0,0,0,0,0,0},
	'{28,28,28,28,28,28,0,0,0,0,0,0,0,0,0,0},
	'{28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{40,40,40,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,36,36,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,36,36,36,0,0,0},
	'{36,36,36,36,36,36,36,36,36,36,36,36,36,0,0,0},
	'{36,36,36,36,36,36,36,36,36,36,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{36,36,36,36,36,36,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,19,19,19,0,0,0,0,0,0,0},
	'{19,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0}
	};

	harry_jump <=
	'{
	'{0,0,0,0,0,0,0,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,0,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,28,28,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,28,28,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,28,28,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,28,28,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,40,40,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,36,36},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,36,36},
	'{0,0,0,0,0,36,36,36,36,36,36,36,36,36,36,36},
	'{0,0,0,0,0,36,36,36,36,36,36,36,36,36,36,36},
	'{0,0,0,36,36,36,36,36,36,36,36,36,36,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,36,0,0,0},
	'{0,0,0,36,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,36,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,36,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,36,52,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,0,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,0,19,20,19,20,19,0,0,0,0},
	'{0,0,0,0,0,0,0,19,19,19,19,19,19,19,0,0},
	'{0,0,0,0,0,0,0,19,19,19,19,19,19,19,0,0},
	'{0,0,0,0,0,0,0,19,19,19,19,19,19,19,19,19},
	'{0,0,0,0,0,0,0,19,19,19,19,19,19,19,19,19},
	'{19,19,19,19,0,0,0,19,19,19,19,0,0,0,19,19},
	'{19,19,19,19,0,0,0,19,19,19,19,0,0,0,19,19},
	'{0,0,0,19,19,19,19,19,19,0,0,0,0,0,19,19},
	'{0,0,0,19,19,19,19,19,19,0,0,0,0,0,19,19}
	};

	harry_run1 <=
	'{
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,24,24,24,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,44,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,40,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,36,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,0,0,0,52,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,36,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,19,0,0,0,19,0,0,0,0,0},
	'{0,0,0,0,0,19,19,0,0,0,19,0,0,0,0,0},
	'{0,19,19,19,19,19,19,0,0,0,19,0,0,0,0,0},
	'{0,19,19,0,0,0,0,0,0,0,19,0,0,0,0,0},
	'{0,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,19,19,0,0,0,0,0,0,0,0,0,19,19,19,19},
	'{0,0,0,0,0,0,0,0,0,0,0,0,19,19,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	harry_run2 <=
	'{
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,28,44,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,40,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,19,19,19,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,19,19,19,19,19,0,0,0},
	'{0,0,0,0,0,0,0,0,19,0,0,0,19,0,0,0},
	'{0,0,0,0,0,0,0,19,19,19,0,19,19,0,0,0},
	'{0,0,0,19,19,19,19,19,19,19,19,19,0,0,0,0},
	'{0,0,0,19,19,0,0,0,19,0,0,0,0,0,0,0},
	'{0,0,0,19,19,0,0,0,19,0,0,0,0,0,0,0},
	'{0,0,0,19,19,0,0,0,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,19,19,19,0,0,0,0,0}
	};

	harry_run3 <=
	'{
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,28,44,0,0,0,0,0,0,0},
	'{0,0,0,0,0,28,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,40,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,19,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,19,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,19,0,0,0,19,19,0,0,0,0},
	'{0,0,0,0,0,19,19,0,0,0,19,19,19,0,0,0},
	'{0,0,0,19,19,19,19,0,0,0,0,0,19,0,0,0},
	'{0,0,0,19,19,19,19,0,0,0,0,0,0,0,0,0},
	'{0,0,0,19,19,19,0,0,0,0,19,0,0,0,0,0},
	'{0,0,0,19,19,0,0,0,0,0,19,0,0,0,0,0},
	'{0,0,0,19,19,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,19,19,0,0,0,0,0,0,0,19,0,0,0},
	'{0,0,0,19,19,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,19,19,0,0,0,0,0,0,0,0,0}
	};

	harry_run4 <=
	'{
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,24,24,24,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,44,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,40,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,36,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,0,0,0,52,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,36,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,0,0,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,19,19,0,0,0,19,19,0,0,0,0},
	'{0,0,0,19,19,19,19,0,0,0,19,19,19,19,0,0},
	'{0,19,19,19,19,0,0,0,0,0,0,0,19,19,0,0},
	'{0,19,19,19,19,0,0,0,0,0,0,0,19,19,0,0},
	'{0,19,19,19,19,0,0,0,0,0,0,0,19,19,0,0},
	'{19,19,19,0,0,0,0,0,0,0,0,0,19,19,19,19},
	'{19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	harry_run5 <=
	'{
	'{0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,24,24,24,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,28,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,28,44,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,28,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,44,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,52,36,0,0},
	'{0,0,0,0,36,36,36,36,36,36,36,36,36,36,0,0},
	'{0,0,0,36,36,36,36,36,36,36,36,36,0,0,0,0},
	'{0,36,36,36,36,36,36,36,36,36,36,0,0,0,0,0},
	'{0,36,36,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,36,36,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,36,36,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,36,36,36,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,0,0,0,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,19,19,19,0,0},
	'{0,0,0,0,0,0,19,19,19,19,19,19,19,19,0,0},
	'{19,19,19,0,0,0,19,19,19,0,0,0,19,19,0,0},
	'{0,19,19,0,0,19,19,0,0,0,0,0,19,19,0,0},
	'{0,0,19,19,19,19,19,0,0,0,0,0,19,19,0,0},
	'{0,0,0,19,19,19,19,0,0,0,0,0,19,19,19,19},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	harry_vine <=
	'{
	'{17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0},
	'{17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0},
	'{68,68,68,68,0,0,68,68,0,0,0,0,0,0,0,0},
	'{68,68,68,68,0,0,68,68,0,0,0,0,0,0,0,0},
	'{68,68,68,68,0,0,68,68,0,0,0,0,0,0,0,0},
	'{68,68,84,68,0,0,68,68,0,0,0,0,0,0,0,0},
	'{68,68,0,0,0,0,68,68,0,0,0,0,0,0,0,0},
	'{68,68,0,0,0,0,68,68,0,0,0,0,0,0,0,0},
	'{67,67,0,0,0,0,67,67,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,60,60,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,60,60,0,0,0,0,0,0,0,0},
	'{60,60,60,60,76,76,76,60,0,0,0,0,0,0,0,0},
	'{60,60,60,60,60,60,60,60,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,76,60,0,0,0,0,0,0,0,0,0,0,0,0},
	'{76,76,76,76,0,0,0,0,0,0,0,0,0,0,0,0},
	'{45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0},
	'{29,29,29,29,0,0,29,29,29,29,29,29,0,0,0,0},
	'{29,29,29,29,0,0,29,29,0,0,29,29,0,0,0,0},
	'{29,29,29,29,29,29,29,29,0,0,29,29,29,29,0,0},
	'{29,29,29,29,29,29,29,29,0,0,29,29,29,29,0,0},
	'{29,29,29,29,29,29,29,29,0,0,0,0,29,29,0,0},
	'{29,29,29,29,29,29,29,29,0,0,0,0,29,29,0,0},
	'{0,0,29,29,29,29,0,0,0,0,0,0,29,29,29,29},
	'{0,0,29,29,29,29,0,0,0,0,0,0,29,29,29,29}
	};

	harry_climb1 <=
	'{
	'{0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0},
	'{0,0,0,50,51,50,50,50,51,0,0,0,0,0,0,0},
	'{0,0,0,68,84,68,68,68,84,0,0,0,0,0,0,0},
	'{0,0,0,68,84,68,68,68,84,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,84,68,68},
	'{0,0,0,60,76,60,60,60,76,0,0,0,0,60,60,60},
	'{0,0,0,60,76,60,60,60,76,60,0,0,0,76,76,76},
	'{0,0,0,60,76,60,60,60,60,60,76,76,60,0,0,0},
	'{76,76,76,60,60,60,60,60,60,60,60,76,60,0,0,0},
	'{60,60,60,60,60,60,60,60,76,0,0,0,0,0,0,0},
	'{60,60,60,60,60,60,60,60,76,0,0,0,0,0,0,0},
	'{60,60,60,60,60,60,60,60,76,0,0,0,0,0,0,0},
	'{0,0,0,76,76,76,76,76,76,0,0,0,0,0,0,0},
	'{0,0,0,45,45,45,45,45,45,45,0,0,0,0,0,0},
	'{0,0,0,29,29,29,29,29,29,29,29,29,29,0,0,0},
	'{0,0,0,29,29,29,29,29,29,29,29,29,29,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,29,29,29},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,0,0,0,0,0,0},
	'{29,29,29,29,29,29,0,0,0,0,0,0,0,0,0,0}
	};

	harry_climb2 <=
	'{
	'{0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0},
	'{0,0,0,0,0,0,0,51,50,50,50,51,50,0,0,0},
	'{0,0,0,0,0,0,0,84,68,68,68,84,68,0,0,0},
	'{0,0,0,0,0,0,0,84,68,68,68,84,68,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{68,68,84,0,0,0,0,0,0,0,0,0,0,0,0,0},
	'{60,60,60,0,0,0,0,76,60,60,60,76,60,0,0,0},
	'{76,76,76,0,0,0,60,76,60,60,60,76,60,0,0,0},
	'{0,0,0,60,76,76,60,60,60,60,60,76,60,0,0,0},
	'{0,0,0,60,76,60,60,60,60,60,60,60,60,76,76,76},
	'{0,0,0,0,0,0,0,76,60,60,60,60,60,60,60,60},
	'{0,0,0,0,0,0,0,76,60,60,60,60,60,60,60,60},
	'{0,0,0,0,0,0,0,76,60,60,60,60,60,60,60,60},
	'{0,0,0,0,0,0,0,76,76,76,76,76,76,0,0,0},
	'{0,0,0,0,0,0,45,45,45,45,45,45,45,0,0,0},
	'{0,0,0,29,29,29,29,29,29,29,29,29,29,0,0,0},
	'{29,29,29,29,29,29,29,29,29,29,29,29,29,0,0,0},
	'{29,29,29,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{29,29,29,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{29,29,29,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{29,29,29,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{29,29,29,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{29,29,29,29,29,29,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,0,0,0},
	'{0,0,0,0,0,0,0,0,0,0,29,29,29,29,29,29}
	};

	
	end
		/*harry state codes:
		0: harry standing
		1: harry_jump
		2: harry run 1
		3:	harry run 2
		4: harry run 3
		5: harry run 4
		6: harry run 5
		7: harry vine
		8: harry_climb1
		9: harry_climb2
		*/
		always_comb
			begin
				case(harry_state)
					4'b0000: harry_animation = harry;
					4'b0001: harry_animation = harry_jump;
					4'b0010: harry_animation = harry_run1;
					4'b0011: harry_animation = harry_run2;
					4'b0100: harry_animation = harry_run3;
					4'b0101: harry_animation = harry_run4;
					4'b0110: harry_animation = harry_run5;
					4'b0111: harry_animation = harry_vine;
					4'b1000: harry_animation = harry_climb1;
					4'b1001: harry_animation = harry_climb2;
					default: ;
				endcase
			end

endmodule 