# Application / Network configuration
#
# L1 - 2 inputs
# L1 - 52 output
# L2 - 52 input (the bias is automatically added)
# L2 - 73 output
# L3 - 73 input (the bias is automatically added)
# L3 - 3 output
#                 I1  O1  O2  O3
KLAYERS			= [2, 52, 73, 3]
KNB_INPUTS		= 2
KNB_OUTPUTS		= 3

# KMLPN_TAN0 = libm tanh
# KMLPN_TAN1 = Lambert's tanh approximation
# KMLPN_TAN2 = Ultrafast tanh approximation
#
KNON_LINEAR		= "KMLPN_TAN2"

KGAIN			= 0.005
KMOMENTUM		= 0.0
KEPOCHS			= 1000000

# Some Input/Output samples for rapid validation
#
#					 Input -x -y			Class -1 -2 -3
KVALIDATION		= [
					[ 0.490344,  0.051584,  0.98, -0.98, -0.98],
					[ 0.458057, -0.458232,  0.98, -0.98, -0.98],
					[ 0.266116,  0.944208, -0.98,  0.98, -0.98],
					[-0.002234, -0.117944, -0.98,  0.98, -0.98],
					[ 0.834344,  0.854564, -0.98, -0.98,  0.98]
				  ]
