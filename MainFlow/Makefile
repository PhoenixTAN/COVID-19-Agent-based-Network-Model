main: main.cpp init.o agent.o event.o meeting.o non_transmission_event.o social_activity.o stay_alone.o transmission_event.o clock.o hour.o
	g++ -o main main.cpp init.o agent.o event.o meeting.o non_transmission_event.o social_activity.o stay_alone.o transmission_event.o clock.o hour.o

init.o: ./init/cpp/init.cpp 
	g++ -c -o init.o ./init/cpp/init.cpp

agent.o: ./agent/cpp/agent.cpp
	g++ -c -o agent.o ./agent/cpp/agent.cpp

event.o: ./event/cpp/event.cpp
	g++ -c -o event.o ./event/cpp/event.cpp

meeting.o: ./event/cpp/meeting.cpp
	g++ -c -o meeting.o ./event/cpp/meeting.cpp

non_transmission_event.o: ./event/cpp/non_transmission_event.cpp
	g++ -c -o non_transmission_event.o ./event/cpp/non_transmission_event.cpp

social_activity.o: ./event/cpp/social_activity.cpp
	g++ -c -o social_activity.o ./event/cpp/social_activity.cpp

stay_alone.o: ./event/cpp/stay_alone.cpp
	g++ -c -o stay_alone.o ./event/cpp/stay_alone.cpp

transmission_event.o: ./event/cpp/transmission_event.cpp
	g++ -c -o transmission_event.o ./event/cpp/transmission_event.cpp

clock.o: ./time/cpp/clock.cpp
	g++ -c -o clock.o ./time/cpp/clock.cpp

hour.o: ./time/cpp/hour.cpp
	g++ -c -o hour.o ./time/cpp/hour.cpp
