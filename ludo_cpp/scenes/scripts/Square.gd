extends Sprite



var Id:int=0

func _ready():
	pass # Replace with function body.
func SetId(id):
	Id=id
	get_node("B1").text=String(Id)

