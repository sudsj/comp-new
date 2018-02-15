if(lowlm%4 == 0 || lowlm%4 == 2){
 				For(i,1,lowlm+1){
 					if(i%4 == 0 || i%4 == 1){
 						g1 += i;
 					}else g2 += i;
 				}
 			}else if(lowlm%4 == 3){
 				 num = lowlm/4;
 				 For(i,1,num+1){
 				 	g1 += i;
 				 }
 				 For(i,lowlm - num,lowlm+1){
 				 	g1 += i;
 				 }
 				 For(i,num+1,lowlm-num-1){
 				 	g2 += i;
 				 }
 			}else{
 				num = lowlm/4;
 				For(i,1,num+1){
 					g1 += i;
 				}
 				For(i,lowlm - num,lowlm+1){
 					g1 += i;
 				}
 				For(i,num+1,lowlm-num-1){
 					g2 += i;
 				}
 			}