int fast_sm(){

    if(!r0 && r1 && r2 && r3 && r4 && r5){
      state = -3;
    }
    else if(!r0 && !r1 && r2 && r3 && r4 && r5){
      state = -2;
    }
    else if(r0 && !r1 && !r2 && r3 && r4 && r5){
      state = -1;
    }
    else if(r0 && r1 && !r2 && !r3 && r4 && r5){
      state = 0;
    }
    else if(r0 && r1 && r2 && !r3 && !r4 && r5){
      state = 1;
    }
    else if(r0 && r1 && r2 && r3 && !r4 && !r5){
      state = 2;
    }
    else if(r0 && r1 && r2 && r3 && r4 && !r5){
      state = 3;
    }
    else if(r0 && r1 && r2 && r3 && r4 && r5){
      // All white
      state = last_state > 0 ? 4 : -4;
      //state = 0;
    }
    else if(!r0 && !r1 && !r2 && !r3 && !r4 && !r5){
      // All black
      state = 0;
    }
    else{
      // Dunno
      // state = last_state > 0 ? 2 : -2;
    }
}

void falcon_sm(){
  
    if(bitmap == 0){
      // All white
      //state = last_state > 0 ? 4 : -4;
      state = 0;
      return;
    }
    else if(bitmap == 1 || bitmap == 3 || bitmap == 5 || bitmap == 7 || bitmap == 15){
      // Far Right
      state = 4;
      return;
    }
    else if(bitmap == 2){
      state = 3;
      return;
    }
    else if(bitmap == 4 || bitmap == 6){
      state = 2;
      return;
    }
    else if(bitmap == 4){
      state = 1;
      return;
    }
    else if(bitmap == 8){
      state = -1;
      return;
    }
    else if(bitmap == 24){
      state = -2;
      return;
    }
    else if(bitmap == 16){
      state = -3;
      return;
    }
    else if(bitmap == 32 || bitmap == 40 || bitmap == 48 || bitmap == 56){
      state = -4;
      return;
    }
    else{
      // Dunno
      state = last_state > 0 ? 1 : -1;
    }
}
