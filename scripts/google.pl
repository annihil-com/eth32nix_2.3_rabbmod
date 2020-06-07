#!/usr/bin/perl -w
#eth32_nix google script
#Coded by jaggy
use strict;

#make a variable to store all links in
my @links;

#get the user input
my $linky = join (" ", @ARGV);

#make a $search for channel replying
my $search = $linky;

#swap all white spaces for %20
$linky =~ s/ /%20/g;

#create the fulllink...
my $fullLink = "http://www.google.be/search?hl=en&q=$linky";

#get the link and split it
use LWP::UserAgent;
my $ua = LWP::UserAgent->new;
$ua->agent('Mozilla/5.0');
my $response = $ua->get($fullLink);
my @source = split (/</, $response->content);

#check out the source, and get all links
foreach (@source) {
	if ($_ =~ /a href="http/g and $_ !~ /google/g) {
		s/a href=//g;
		s/"//g;
		if ($_ =~ /(.*?)class(.*?)$/g) {
			push @links,$1;
		}
	}
}

print 'Top 3 : ' . $links[0] . $links[1] . $links[2] . "\n";
print "et_str<say After googling for $search i got this:>et_end\n";
print "et_str<say Top 3: $links[0] $links[1] $links[2]>et_end\n";
