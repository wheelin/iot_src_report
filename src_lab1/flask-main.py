#! /usr/bin/env python
#-*- coding: utf-8 -*-

import sys
import time
import logging
import configpi
import os

file_path = os.path.dirname(__file__)
sys.path.insert(0, file_path)

from flask import Flask, render_template, jsonify, Response
from backend import Backend

app = Flask(__name__)

backend = Backend()

@app.route('/', strict_slashes=False)
def index():
    # returns a html page with a list of routes
    return render_template("index.html", title=configpi.name)
    
#######################################################################################################################
############# NETWORK #################################################################################################
#######################################################################################################################

"""
@api {get} /network/preview  get_network_config
@apiName get_network_config
@apiGroup User

@apiSuccess {JSON} Table Network's Information.

@apiDescription Gets the configuration of the Z-Wave network in a JSON format
"""
    
@app.route('/network/preview', strict_slashes=False)
def network_preview():
    return backend.network_preview()




"""
@api {get} /network/configureNodes/<int:Group_interval>/<int:Group_reports>/<int:Wake-up_interval> set_nodes_configuration
@apiName set_nodes_configuration
@apiGroup Admin

@apiParam {Number} Group_Interval Number of seconds between measurements transmissions
@apiParam {Number} Group_Reports a Number identifying measurements sent
@apiParam {Number} Wake-up_Interval Number of seconds between two node's wake-ups  

@apiSuccess {String} Message Description of the new nodes' configuration.

@apiDescription Configure all nodes of the network with a predefined configuration
"""
@app.route('/network/configureNodes/<int:Grp_interval>/<int:Grp_reports>/<int:Wakeup_interval>', strict_slashes=False)
def network_configureNodes(Grp_interval,Grp_reports,Wakeup_interval):
    # configure all the nodes of the network with a specific configuration
    return backend.set_sensor(Grp_interval,Grp_reports,Wakeup_interval)  
    
"""
@api {get} /network/nodesConfiguration Nodes configuration
@apiName Networks' Nodes configuration
@apiGroup Admin

@apiSuccess {html} Table Describing of the nodes' configuration.

@apiDescription Gets a html with the list of nodes and their configuration parameters

"""

@app.route('/network/nodesConfiguration', strict_slashes=False)
def network_nodesConfiguration():
    # gets a html with the list of nodes with their config parameters
    return backend.network_nodesConfiguration()  ######## a revoir




    
"""
@api {get} /network/start start_network
@apiName start_network
@apiGroup Admin

@apiSuccess {String} Message Confirmation that the Z-Wave Network Restarted

@apiDescription Starts the openzwave software representation of the network

"""

@app.route('/network/start', strict_slashes=False)
def start():
    # start software representation
    backend.start()
    return "Z-Wave Network Started"




"""
@api {get} /network/stop stop_netowrk
@apiName stop_netowrk
@apiGroup Admin

@apiSuccess {String} Message Confirmation that the Z-Wave Network has stopped

@apiDescription Stops the openzwave software representation of the network

"""

@app.route('/network/stop', strict_slashes=False)
def stop():
    # stop the software representation
    backend.stop()
    time.sleep(2)
    return "Z-Wave Network Stopped"




"""
@api {get} /network/reset Reset Network
@apiName Reset Network   
@apiGroup Admin

@apiSuccess {String} Message Confirmation that the Z-Wave Network has been reset

@apiDescription Resets the network's controller

"""

@app.route('/network/reset', strict_slashes=False)
def reset():
    # restart software representation
    backend.reset()
    return "Z-Wave Network Reset"

#######################################################################################################################
############# SENSORS #################################################################################################
#######################################################################################################################
### THESE METHODS WERE SPECIALLY MADE FOR SENSOR NODES #################################################################
#######################################################################################################################
"""
@api {get} /sensors get_sensors
@apiName get_sensors
@apiGroup User

@apiSuccess {String[]} List List of all sensor nodes in the network

@apiDescription Lists all sensors nodes in the network. The controller is excluded.

"""

@app.route('/sensors', strict_slashes=False)
def sensors():
    # returns a list of all sensors in the network (only sensors)
    sensors = backend.get_sensors()
    if type(sensors) is str:
        return sensors
    sensors_list = ""
    for key, val in sensors.items():
        sensors_list += str(key) + "=" + str(val) + "\n"
    return Response(sensors_list, mimetype="text/plain")



"""
@api {get} /sensors/<node_id>/all_measures get_all_measures_sensor
@apiName get_all_measures_sensor
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {Number} battery battery level (%)
@apiSuccess {Number} humidity humidity level (%)
@apiSuccess {Number} luminance luminance level (lux)
@apiSuccess {Number} temperature temperature level (C)
@apiSuccess {String} motion motion state (true or false)
@apiSuccess {Number} updateTime Timestamp at the measures' reception 

@apiSuccessExample {json} Example data on success:
{
  "battery": 100, 
  "controller": "Pi lab1", 
  "humidity": 22, 
  "location": "Room A401",
  "luminance": 60, 
  "motion": false, 
  "sensor": 2, 
  "temperature": 30.0, 
  "updateTime": 1454682568
}
@apiDescription Gets all reasures of a given sensor in a JSON format

"""
    
@app.route('/sensors/<int:node>/all_measures', strict_slashes=False)
def get_all_measures(node):
    return backend.allMeasures(node)



"""
@api {get} /sensors/<node_id>/temperature get_temperature
@apiName get_temperature
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {String} type Type of measurement
@apiSuccess {Number} value Temperature level (C)
@apiSuccess {Number} updateTime Timestamp of the measure

@apiSuccessExample {json} Example data on success:
{
  "controller": "Pi lab1", 
  "location": "Room A401",
  "sensor": 2, 
  "type": "temperature", 
  "updateTime": 1454682568, 
  "value": 30.4
}
@apiDescription Gets temperature of a given sensor in a JSON format

"""

@app.route('/sensors/<int:node>/temperature', strict_slashes=False)
def get_temperature(node):
    return backend.temperature(node)



"""
@api {get} /sensors/<node_id>/humidity get_humidity
@apiName get_humidity
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {String} type type of measurement
@apiSuccess {Number} value humidity level (%)
@apiSuccess {Number} updateTime Timestamp at the measures' reception 

@apiSuccessExample {json} Example data on success:
{
  "controller": "Pi lab1", 
  "location": "Room A401",
  "sensor": 2, 
  "type": "relative humidity", 
  "updateTime": 1454682996, 
  "value": 21
}
@apiDescription Gets humidity of a given sensor in a JSON format

"""

@app.route('/sensors/<int:node>/humidity', strict_slashes=False)
def get_humidity(node):
    return backend.humidity(node)



"""
@api {get} /sensors/<node_id>/luminance get_luminance
@apiName get_luminance
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {String} type type of measurement
@apiSuccess {Number} value luminance level (lux)
@apiSuccess {Number} updateTime Timestamp at the measures' reception 

@apiSuccessExample {json} Example data on success:
{
  "controller": "Pi lab1", 
  "location": "Room A401",
  "sensor": 2, 
  "type": "luminance", 
  "updateTime": 1454682996, 
  "value": 49
}
@apiDescription Gets humidity of a given sensor in a JSON format

"""

@app.route('/sensors/<int:node>/luminance', strict_slashes=False)
def get_luminance(node):
    return backend.luminance(node)



"""
@api {get} /sensors/<node_id>/motion get_motion
@apiName get_motion
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {String} type type of measurement
@apiSuccess {Number} value motion state (boolean)
@apiSuccess {Number} updateTime Timestamp at the measures' reception 

@apiSuccessExample {json} Example data on success:
{
  "controller": "Pi lab1", 
  "location": "Room A401",
  "sensor": 2, 
  "type": "sensor", 
  "updateTime": 1454682996, 
  "value": true
}
@apiDescription Gets motion of a given sensor in a JSON format

"""

@app.route('/sensors/<int:node>/motion', strict_slashes=False)
def get_motion(node):
    return backend.motion(node)





"""
@api {get} /sensors/<node_id>/set/<parameter>/to/<value> set_parameter
@apiName set_parameter
@apiGroup Admin

@apiParam {Number} node_id Sensor's unique ID
@apiParam {Number} parameter Parameter's unique index
@apiParam {Number} value new value of the parameter 

@apiSuccess {String} parameter parameter's new value

@apiDescription Sets the value of a given parameter of a sensor

"""

@app.route('/sensors/<int:node>/set/<int:param>/to/<int:value>', strict_slashes=False)
def set_config_param(node, param, value):
   # sets a config parameter of a sensor node
    return backend.set_node_config_param(node, param, value)



"""
@api {get} /sensors/<node_id>/get/<parameter> get_parameter
@apiName get_parameter
@apiGroup Admin

@apiParam {Number} node_id Sensor's unique ID
@apiParam {Number} parameter Parameter's unique index

@apiSuccess {String} parameter parameter's value

@apiDescription Gets the value of a given parameter of a sensor

"""

@app.route('/sensors/<int:node>/get/<int:param>', strict_slashes=False)
def get_config_param(node, param):
    # gets a config parameter of a sensor node
    return backend.get_node_config_param(node, param)



"""
@api {get} /nodes get_nodes
@apiName get_nodes
@apiGroup User

@apiSuccess {String[]} List List of all nodes in the network

@apiDescription Lists all nodes in the network

"""
        
@app.route('/nodes', strict_slashes=False)
def nodes():
    # gets a list of all nodes in the network and not only sensors
    nodes = backend.get_nodes()
    if type(nodes) is str:
        return nodes
    nodes_list = ""
    for key, val in nodes.items():
        nodes_list += str(key) + "=" + str(val) + "\n"
    return Response(nodes_list, mimetype="text/plain")



"""
@api {get} /nodes/add add_node
@apiName add_node
@apiGroup Admin

@apiSuccess {String} Message Node added successfully

@apiDescription Adds Node to the network

"""

@app.route('/nodes/add', strict_slashes=False)
def add_node():
    # passes controller to inclusion mode
    return backend.addNode()



"""
@api {get} /nodes/remove remove_node
@apiName remove_node
@apiGroup Admin

@apiSuccess {String} Message Node removed successfully

@apiDescription Removes Node from the network

"""

@app.route('/nodes/remove', strict_slashes=False)
def remove_node():
    # passes controller to exclusion mode
    return backend.removeNode()



"""
@api {get} /nodes/<node_id>/battery get_battery_level
@apiName get_battery_level
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} controller Controller name
@apiSuccess {String} location Location of the sensor
@apiSuccess {String} sensor Sensor's ID
@apiSuccess {String} type type of measurement
@apiSuccess {Number} value battery level (%)
@apiSuccess {Number} updateTime Timestamp at the measures' reception 

@apiSuccessExample {json} Example data on success:
{
  "controller": "Pi lab1", 
  "location": "Room A401",
  "sensor": 2, 
  "type": "battery", 
  "updateTime": 1454684168, 
  "value": 100
}
@apiDescription Gets the battery level of a sensor in a JSON format

"""

@app.route('/nodes/<int:node>/battery', strict_slashes=False)
def get_battery(node):
    return backend.battery(node)



"""
@api {get} /nodes/<node_id>/setLocationTo/<value> set_location
@apiName set_location
@apiGroup Admin

@apiParam {Number} node_id Sensor's unique ID
@apiParam {String} value new location value  

@apiSuccess {String} location location's new value

@apiDescription Sets location of a given node

"""

@app.route('/nodes/<int:node>/setLocationTo/<value>', strict_slashes=False)
def set_node_location(node, value):
    return backend.set_node_location(node, value)



"""
@api {get} /nodes/<node_id>/setNameTo/<value> set_name
@apiName set_name
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID
@apiParam {String} value new name value  

@apiSuccess {String} name name's new value

@apiDescription Sets name of a given node

"""

@app.route('/nodes/<int:node>/setNameTo/<value>', strict_slashes=False)
def set_node_name(node, value):
    return backend.set_node_name(node, value)



"""
@api {get} /nodes/<node_id>/getLocation get_location
@apiName get_location
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} location location's value

@apiDescription Gets location of a given node

"""

@app.route('/nodes/<int:node>/getLocation', strict_slashes=False)
def get_node_location(node):
    return backend.get_node_location(node)



"""
@api {get} /nodes/<node_id>/getName get_name
@apiName get_name
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String} name name's value

@apiDescription Gets name of a given node

"""

@app.route('/nodes/<int:node>/getName', strict_slashes=False)
def get_node_name(node):
    return backend.get_node_name(node)



"""
@api {get} /nodes/<node_id>/neighbors get_neighbours
@apiName get_neighbours
@apiGroup User

@apiParam {Number} node_id Sensor's unique ID

@apiSuccess {String[]} neighbors list of a node's neighbours

@apiDescription Gets list of a node's neighbours

"""

@app.route('/nodes/<int:node>/neighbors', strict_slashes=False)
def get_neighbors(node):
    return backend.get_neighbors(node)



#################################################################
#################################################################    


from logging import FileHandler, Formatter, DEBUG

if __name__ == '__main__':
    try:
        backend.start()
        file_handler = FileHandler("flask.log")
        file_handler.setLevel(DEBUG)
        file_handler.setFormatter(Formatter('%(asctime)s %(levelname)s: %(message)s [in %(pathname)s:%(lineno)d]'))
        app.logger.addHandler(file_handler)

        app.run(host='::', debug=False, use_reloader=False)

    except KeyboardInterrupt:
        backend.stop()
