 
all:getmax getmin
getmax: getmax_main.cpp getmax.cpp
	cl -o getmax getmax_main.cpp getmax.cpp  -lm
getmin:getmin_main.cpp getmin.cpp
	cl -o getmin getmin_main.cpp getmin.cpp -lm
 
clean:
	rm *.o getmax getmin
