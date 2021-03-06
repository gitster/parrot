#!./parrot
# Copyright (C) 2005-2009, Parrot Foundation.
#
# random.pir N         (N = 900000 for shootout)
# by Joshua Isom

.sub main :main
	.param pmc argv
	$S0 = argv[1]
	$I0 = $S0
while_1:
	gen_random(100.0)
	dec $I0
	if $I0 > 1 goto while_1
	$N0 = gen_random(100.0)
	$P0 = new 'FixedFloatArray'
	$P0 = 1
	$P0[0] = $N0
	$S0 = sprintf "%.9f\n", $P0
	print $S0
	.return(0)
.end

.const num IM = 139968.0
.const num IA = 3877.0
.const num IC = 29573.0

.sub gen_random
	.param num max
	.local num last
	last = 42.0
loop:
	$N0 = last
	$N0 *= IA
	$N0 += IC
	$N0 %= IM
	$N1 = max
	$N1 *= $N0
	$N1 /= IM
	last = $N0
	.yield($N1)
	get_params "0", max
	goto loop
.end


# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:
