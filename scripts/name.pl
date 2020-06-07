#!/usr/bin/perl -w
use strict;

$|=1;

if (@ARGV < 2 or  $ARGV[0] !~ /\d(.*?)/) {
	print "Not the right arguments...\n";
	print "Usage: /!SpamOnTime <seconds> <spaming text>\n";
	print "Example: /!SpamOnTime 60 I love spaming\n";
	exit;
}

my $TimeToSleep = shift;
my $SpamWithThis = join (" ", @ARGV);

while (1) {
	print "et_str<say $SpamWithThis>et_end\n";
	sleep $TimeToSleep;
}
