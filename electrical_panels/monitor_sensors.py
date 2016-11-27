import boto3

client = boto3.client('iot')

leftName = 'ElectricalPanel1'

# Get last version
leftPanel = client.describe_thing(thingName=leftName)

# Read from left panel

left = 0

# Update left panel thing
response = client.update_thing(
		thingName=leftName,
		thingTypeName='ElectricalPanel',
		attributePayload={
			'attributes': {
				'Current_Amps': str(left)
			},
			'merge': True
		},
		expectedVersion=leftPanel['version'])

rightName = 'ElectricalPanel2'

# Get last version
rightPanel = client.describe_thing(thingName=rightName)

# Read from right panel

right = 0

# Update right panel thing
response = client.update_thing(
		thingName=rightName,
		thingTypeName='ElectricalPanel',
		attributePayload={
			'attributes': {
				'Current_Amps': str(right)
			},
			'merge': True
		},
		expectedVersion=rightPanel['version'])
