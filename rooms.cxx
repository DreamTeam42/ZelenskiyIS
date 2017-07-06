#encoding "utf8"

Rooms -> AnyWord<wff=/([1-9](-x)?|одно|дву|двух|трех|четырех|пяти)-?(комнатн(ая|ую)|к|кк)/>;
Rooms -> AnyWord<wff=/[1-9]|одна|две|три|четыре|пять/> AnyWord<wff=/комнат|комнаты/>;
Rooms -> AnyWord<wff=/([1-9](-x)?|одно|дву|двух|трех|четырех|пяти)/> AnyWord<wff=/(комнатн(ая|ую)|к|кк)/>;

RoomsCnt -> Rooms interp (Rooms.Rooms);