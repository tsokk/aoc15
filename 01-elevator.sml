val infile = TextIO.openIn "input/1.txt";

fun readList infile =
    if TextIO.endOfStream infile then nil
    else TextIO.inputN (infile, 1) :: readList infile;

fun parenToNum "(" = 1
  | parenToNum ")" = ~1
  | parenToNum x   = 0;

val xs = map parenToNum (readList infile);

val answerPartOne = foldr op + 0 xs;

fun cumsum ([], sum, acc) = nil
  | cumsum (x::xs, sum, acc) =
    let val y = sum + x
    in acc @ [y] @ cumsum (xs, y, acc)
    end;

fun findPos ([], pos) = 0
  | findPos (x::xs, pos) =
    if x = ~1  then pos
    else findPos (xs, pos + 1)
	
val answerPartTwo = findPos (cumsum (xs, 0, []), 1);
