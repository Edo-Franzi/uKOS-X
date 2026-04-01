# Application / Network configuration
#
# L1 - 2 inputs
# L1 - 12 output
# L2 - 12 input (the bias is automatically added)
# L2 - 24 output
# L3 - 24 input (the bias is automatically added)
# L3 - 5 output
#                 I1  O1  O2  O3
KLAYERS			= [2, 12, 24, 5]
KNB_INPUTS		= 2
KNB_OUTPUTS		= 5

# KMLPN_TAN0 = libm tanh
# KMLPN_TAN1 = Lambert's tanh approximation
# KMLPN_TAN2 = Ultrafast tanh approximation (~2% precision)
# KMLPN_TAN3 = Fastest tanh approximation (less precise)
# KMLPN_RELU = Ultrafast relu
# KMLPN_LINE = Ultrafast linear
# KMLPN_SMAX = Ultrafast softmax
#
KNON_LINEAR		= "KMLPN_TAN2"

KGAIN			= 0.005
KMOMENTUM		= 0.0
KEPOCHS			= 200000

# Some Input/Output samples for rapid validation
#
#					 Input -x -yy			Class -1 -2 -3 -4 -5
KVALIDATION		= [
					[-0.988388,	0.867081,	0.98,	-0.98,	-0.98,	-0.98,	-0.98],
					[0.757057,	0.295996,	-0.98,	0.98,	-0.98,	-0.98,	-0.98],
					[0.327959,	-0.888219,	-0.98,	-0.98,	-0.98,	0.98,	-0.98],
					[-0.478465,	-0.454157,	-0.98,	-0.98,	0.98,	-0.98,	-0.98],
					[-0.561333,	-0.588802,	-0.98,	-0.98,	0.98,	-0.98,	-0.98],
					[0.474768,	-0.188733,	-0.98,	-0.98,	-0.98,	0.98,	-0.98]
				  ]
