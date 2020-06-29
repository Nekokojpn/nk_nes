
struct registers {
   a: i8,   //Accumulator
   x: i8,   //Index register
   y: i8,   //Index register
   pc: i16, //Program counter
   sp_hi: i8,  //Stack pointer
   sp_lo: i8,  //Stack pointer
   p: i8 //Processer status register
}

pub fn execute(opcode: i32) {
   if opcode == 0xA1 {
      println!("no");
   }
}


