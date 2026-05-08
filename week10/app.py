from flask import Flask, render_template, request

# Create the Flask app instance
app = Flask(__name__)

# Define the home route
@app.route("/")
def index():
    # This renders the form for the user to fill out
    return render_template("index.html")

# Define the registration route
@app.route("/register", methods=["POST"])
def register():
    # Read "name" and "sport" from the submitted form data
    name = request.form.get("name")
    sport = request.form.get("sport")

    # Basic server-side validation for presence of data
    if not name or not sport:
        return render_template("failure.html")

    # If everything looks good, show the success page
    return render_template("success.html")
